#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <iostream>
#include <future>
#include <set>

using namespace std;

bool is_pos_on_map(int pos_x, int pos_y, int dim_x, int dim_y) {
  return !(pos_x < 0 || pos_y < 0 || pos_x >= dim_x || pos_y >= dim_y);
}

struct patrol_guard {
  pair<int, int> pos{ 0, 0 };
  pair<int, int> dir{ 0, -1 };

  bool operator==(const patrol_guard& other) const {
    return pos == other.pos && dir == other.dir;
  }

  bool operator!=(const patrol_guard& other) const {
    return !(*this == other);
  }

  pair<int, int> peek_next_position() {
    return { pos.first + dir.first, pos.second + dir.second };
  }

  void move_next_position() {
    pos.first += dir.first;
    pos.second += dir.second;
  }

  void rotate() {
    if (dir == std::make_pair(0, -1))
      dir = std::make_pair(1, 0);
    else if (dir == std::make_pair(1, 0))
      dir = std::make_pair(0, 1);
    else if (dir == std::make_pair(0, 1))
      dir = std::make_pair(-1, 0);
    else if (dir == std::make_pair(-1, 0))
      dir = std::make_pair(0, -1);
    else
      throw std::runtime_error("Error in rotate logic!");
  }

  bool is_on_map(int dim_x, int dim_y) {
    return is_pos_on_map(pos.first, pos.second, dim_x, dim_y);
  }
};

struct cell {
  bool has_obstacle{ false };
  bool is_visited{ false };
  patrol_guard visited_guard;
};

cell char_to_cell(char c) {
  if (c == '#')
    return cell{ .has_obstacle = true };
  else
    return cell{};
}

vector<vector<char>> read_file() {
  ifstream infile("6a.txt");
  vector<vector<char>> csv_rows;

  for (string line; getline(infile, line);) {
    istringstream ss(line);
    vector<char> row;

    char value{ 0 };
    while (ss >> value) {
      row.push_back(value);
    }

    csv_rows.push_back(move(row));
  }

  return csv_rows;
}

tuple<vector<vector<cell>>, patrol_guard>
construct_game_state(const vector<vector<char>>& map_chars) {
  vector<vector<cell>> map(map_chars.size());
  patrol_guard guard;

  for (size_t i = 0; i < map_chars.size(); i++) {
    map.at(i).resize(map_chars.at(i).size());
    transform(map_chars.at(i).begin(), map_chars.at(i).end(), map.at(i).begin(), char_to_cell);
  }

  // Find the guard and set his position
  for (size_t i = 0; i < map_chars.size(); i++) {
    auto itr1 = find(map_chars.at(i).begin(), map_chars.at(i).end(), '^');
    if (itr1 != map_chars.at(i).end()) {
      auto index1 = distance(map_chars.at(i).begin(), itr1);
      guard.pos.first = index1;
      guard.pos.second = i;
      break;
    }
  }

  return { map, guard };
}

bool execute_game_tick(vector<vector<cell>>& map, patrol_guard& guard, const patrol_guard& original_guard) {
  if (!map.at(guard.pos.second).at(guard.pos.first).is_visited) {
    map.at(guard.pos.second).at(guard.pos.first).is_visited = true;
    map.at(guard.pos.second).at(guard.pos.first).visited_guard = guard;
  }

  auto next_pos = guard.peek_next_position();

  // Is the next position an obstacle?
  if (is_pos_on_map(next_pos.first, next_pos.second, map.at(0).size(), map.size()) &&
    map.at(next_pos.second).at(next_pos.first).has_obstacle) {
    guard.rotate();
  } else {
    guard.move_next_position();
  }

  return guard.is_on_map(map.at(0).size(), map.size()) &&
    map.at(guard.pos.second).at(guard.pos.first).visited_guard != guard;
}

bool part2_thread(const vector<vector<cell>>& original_map, const patrol_guard& original_guard, size_t i, size_t j) {
  auto copy_map = original_map;
  auto copy_guard = original_guard;

  // Set the obstacle
  copy_map.at(j).at(i).has_obstacle = true;

  while (execute_game_tick(copy_map, copy_guard, original_guard))
    ;

  if (copy_guard.is_on_map(copy_map.at(0).size(), copy_map.size()) &&
    copy_map.at(copy_guard.pos.second).at(copy_guard.pos.first).visited_guard == copy_guard)
    return true;
  return false;
}

int main() {
  // Part 1
  auto map_chars = read_file();

  auto [map, guard] = construct_game_state(map_chars);

  const auto original_map = map;
  const patrol_guard original_guard = guard;

  while (execute_game_tick(map, guard, original_guard))
    ;

  int visited_sum{ 0 };

  auto increment_sum = [&visited_sum](const cell& n) {
    if (n.is_visited)
      visited_sum++;
    };

  // Sum up the is_visited
  for (const auto& map_row : map) {
    for_each(map_row.begin(), map_row.end(), increment_sum);
  }

  cout << visited_sum << '\n';

  // Part 2
  int is_looped_sum{ 0 };
  for (size_t j = 0; j < original_map.size(); j++) {
    for (size_t i = 0; i < original_map.at(0).size(); i += 5) {
      future<bool> ret1 = async(&part2_thread, original_map, original_guard, i, j);
      future<bool> ret2 = async(&part2_thread, original_map, original_guard, i + 1, j);
      future<bool> ret3 = async(&part2_thread, original_map, original_guard, i + 2, j);
      future<bool> ret4 = async(&part2_thread, original_map, original_guard, i + 3, j);
      future<bool> ret5 = async(&part2_thread, original_map, original_guard, i + 4, j);

      if (ret1.get())
        is_looped_sum++;
      if (ret2.get())
        is_looped_sum++;
      if (ret3.get())
        is_looped_sum++;
      if (ret4.get())
        is_looped_sum++;
      if (ret5.get())
        is_looped_sum++;
    }
  }
  cout << is_looped_sum << '\n';
}