use std::io;

fn solve() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let parts: Vec<usize> = input
        .split_whitespace()
        .map(|x| x.parse().unwrap())
        .collect();
    let n = parts[0];
    let k = parts[1];

    let mut a = String::new();
    io::stdin().read_line(&mut a).unwrap();
    let a: Vec<char> = a.trim().chars().collect();

    let mut w_count = a[0..k].iter().filter(|&c| *c == 'W').count();
    let mut min_w = w_count;

    for i in k..n {
        if a[i - k] == 'W' {
            w_count -= 1;
        }
        if a[i] == 'W' {
            w_count += 1;
        }
        min_w = min_w.min(w_count);
    }

    println!("{}", min_w);
}

fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let t: usize = input.trim().parse().unwrap();

    for _ in 0..t {
        solve();
    }
}
