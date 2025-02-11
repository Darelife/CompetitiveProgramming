use std::collections::VecDeque;
use std::io::{self, BufRead};

fn main() {
    let stdin = io::stdin();
    let mut lines = stdin.lock().lines();
    let first_line = lines.next().unwrap().unwrap();
    let mut first_iter = first_line.split_whitespace();
    let n: usize = first_iter.next().unwrap().parse().unwrap();
    let m: i32 = first_iter.next().unwrap().parse().unwrap();

    let second_line = lines.next().unwrap().unwrap();
    let coffee_requirements: Vec<i32> = second_line
        .split_whitespace()
        .map(|x| x.parse().unwrap())
        .collect();

    let mut queue: VecDeque<(usize, i32)> = VecDeque::new();
    for (index, &requirement) in coffee_requirements.iter().enumerate() {
        queue.push_back((index + 1, requirement));
    }

    let mut last_student = 0;

    while let Some((student_index, remaining_coffee)) = queue.pop_front() {
        if remaining_coffee > m {
            queue.push_back((student_index, remaining_coffee - m));
        }
        last_student = student_index;
    }

    println!("{}", last_student);
}
