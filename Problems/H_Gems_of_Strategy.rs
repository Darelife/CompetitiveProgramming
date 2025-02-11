use std::collections::HashMap;
use std::io;

fn solve() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let n: usize = input.trim().parse().unwrap();

    let mut a = String::new();
    io::stdin().read_line(&mut a).unwrap();
    let a: Vec<usize> = a.split_whitespace().map(|x| x.parse().unwrap()).collect();

    let mut freq = HashMap::new();
    for &x in &a {
        *freq.entry(x).or_insert(0) += 1;
    }

    let mut m = 0;
    for &count in freq.values() {
        if count == 2 {
            m += 1;
        }
    }

    println!("{}", m);
}

fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let t: usize = input.trim().parse().unwrap();

    for _ in 0..t {
        solve();
    }
}
