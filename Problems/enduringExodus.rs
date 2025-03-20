use std::io::{self, Read};

fn solve(n: usize, k: usize, m: usize, p: &Vec<usize>, s: &Vec<char>) -> bool {
    for i in 0..n {
        if s[i] == '0' {
            let l = if i >= m + 1 { p[i - m - 1] } else { 0 };
            let r = if i + m < n { p[i + m] } else { p[n - 1] };
            if r - l >= k + 1 {
                return true;
            }
        }
    }
    false
}

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut iter = input.split_whitespace();
    let n: usize = iter.next().unwrap().parse().unwrap();
    let k: usize = iter.next().unwrap().parse().unwrap();
    let s: Vec<char> = iter.next().unwrap().chars().collect();

    let mut p = vec![0; n];
    p[0] = if s[0] == '0' { 1 } else { 0 };
    for i in 1..n {
        p[i] = p[i - 1] + if s[i] == '0' { 1 } else { 0 };
    }

    let mut l = 1;
    let mut r = n;
    while l <= r {
        let m = l + (r - l) / 2;
        if solve(p.len(), k, m, &p, &s) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }

    println!("{}", l);
}
