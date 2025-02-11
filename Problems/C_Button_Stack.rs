use std::io::{self, BufRead};

fn main() {
    let stdin = io::stdin();
    let mut lines = stdin.lock().lines();
    let t: usize = lines.next().unwrap().unwrap().trim().parse().unwrap();
    for _ in 0..t {
        if let Some(Ok(line)) = lines.next() {
            let mut parts = line.split_whitespace();
            let n: i32 = parts.next().unwrap().parse().unwrap();
            let m: i32 = parts.next().unwrap().parse().unwrap();

            if m <= n && (n - m) % 2 == 0 {
                println!("Yes");
            } else {
                println!("No");
            }
        }
    }
}
