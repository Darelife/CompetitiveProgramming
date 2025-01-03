use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut iter = input.split_whitespace();
    let s: Vec<char> = iter.next().unwrap().chars().collect();
    // println!("{:?}", s);
    let n = s.len();
    let mut ans = vec![0; n];
    for i in 0..n - 1 {
        if (s[i] != s[i + 1]) {
            ans[i] = 1;
        }
    }
    if (s[n - 1] == 'a') {
        ans[n - 1] = 1;
    }
    for i in 0..n {
        print!("{} ", ans[i]);
    }
}
