use std::collections::{HashMap, HashSet};
use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut iter = input.split_whitespace();
    let n: usize = iter.next().unwrap().parse().unwrap();
    let s: Vec<char> = iter.next().unwrap().chars().collect();
    let mut st: HashSet<char> = HashSet::new();
    for c in &s {
        st.insert(*c);
    }
    let mut ans = 1e9 as usize + 7;
    let maxx: usize = st.len();
    let mut cnt: HashMap<char, usize> = HashMap::new();
    let mut l = 0;
    let mut r = 0;
    while r < n {
        *cnt.entry(s[r]).or_insert(0) += 1;
        while cnt.len() == maxx {
            ans = std::cmp::min(ans, r - l + 1);
            *cnt.get_mut(&s[l]).unwrap() -= 1;
            if cnt[&s[l]] == 0 {
                cnt.remove(&s[l]);
            }
            l += 1;
        }
        r += 1;
    }
    println!("{}", ans);
}
