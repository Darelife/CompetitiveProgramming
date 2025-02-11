use std::collections::HashSet;
use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut iter = input.split_whitespace();
    let t: usize = iter.next().unwrap().parse().unwrap();
    for i in 0..t {
        let a: i32 = iter.next().unwrap().parse().unwrap();
        let b: i32 = iter.next().unwrap().parse().unwrap();
        let k1: i32 = iter.next().unwrap().parse().unwrap();
        let k2: i32 = iter.next().unwrap().parse().unwrap();
        let q1: i32 = iter.next().unwrap().parse().unwrap();
        let q2: i32 = iter.next().unwrap().parse().unwrap();

        // ordered set of pair of int
        let mut ans = 0;

        let mut v = HashSet::new();
        v.insert((k1 + a, k2 + b));
        v.insert((k1 - a, k2 + b));
        v.insert((k1 + a, k2 - b));
        v.insert((k1 - a, k2 - b));
        v.insert((k1 + b, k2 + a));
        v.insert((k1 - b, k2 + a));
        v.insert((k1 + b, k2 - a));
        v.insert((k1 - b, k2 - a));

        let mut v1 = HashSet::new();
        v1.insert((q1 + a, q2 + b));
        v1.insert((q1 - a, q2 + b));
        v1.insert((q1 + a, q2 - b));
        v1.insert((q1 - a, q2 - b));
        v1.insert((q1 + b, q2 + a));
        v1.insert((q1 - b, q2 + a));
        v1.insert((q1 + b, q2 - a));
        v1.insert((q1 - b, q2 - a));

        for x in &v {
            if v1.contains(x) {
                ans += 1;
            }
        }

        println!("{}", ans);
    }
}
