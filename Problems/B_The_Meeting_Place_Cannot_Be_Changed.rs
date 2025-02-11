use std::cmp::{max, min};
use std::io::{self, Read};
fn check(time: f64, a: &Vec<i32>, b: &Vec<i32>) -> bool {
    let mut l: f64 = -1e9;
    let mut r: f64 = 1e9;
    for i in 0..a.len() {
        l = l.max(a[i] as f64 - b[i] as f64 * time);
        r = r.min(a[i] as f64 + b[i] as f64 * time);
    }
    return l <= r;
}

fn main() {
    let mut input = String::new();
    std::io::stdin().read_to_string(&mut input).unwrap();
    let mut iter = input.split_whitespace();
    let n: usize = iter.next().unwrap().parse().unwrap();
    let a: Vec<i32> = (0..n)
        .map(|_| iter.next().unwrap().parse().unwrap())
        .collect();
    let b: Vec<i32> = (0..n)
        .map(|_| iter.next().unwrap().parse().unwrap())
        .collect();
    // println!("{:?} {:?} {}", a, b, n);
    let mut l: f64 = 0.0;
    let mut r: f64 = 1e9;
    let delta: f64 = 1e-6;

    while r - l > delta {
        let mid = (l + r) / 2.0;
        if check(mid, &a, &b) {
            r = mid;
        } else {
            l = mid;
        }
    }
    println!("{:.6}", l);
}
