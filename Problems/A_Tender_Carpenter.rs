use std::cmp::{max, min};
use std::io::Read;

fn main() {
    let mut input = String::new();
    std::io::stdin().read_to_string(&mut input).unwrap();
    let mut iter = input.split_whitespace();
    let t: usize = iter.next().unwrap().parse().unwrap();
    for i in 0..t {
        let n: i32 = iter.next().unwrap().parse().unwrap();
        let a: Vec<i32> = (0..n)
            .map(|_| iter.next().unwrap().parse().unwrap())
            .collect();
        // println!("{:?}", a);
        let mut ans: i32 = 0;
        for i in 0..(n - 1) as usize {
            if (2 * min(a[i], a[i + 1])) > max(a[i], a[i + 1]) {
                // println!("YES");
                ans = 1;
                break;
            }
        }
        if ans == 1 {
            println!("YES");
        } else {
            println!("NO");
        }
    }
}
