use std::collections::{HashMap, HashSet};
use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut iter = input.split_whitespace();
    let n: usize = iter.next().unwrap().parse().unwrap();
    let m: usize = iter.next().unwrap().parse().unwrap();

    let mut sieve: Vec<HashSet<usize>> = vec![HashSet::new(); 100_005];
    for i in 2..=100_000 {
        if sieve[i].is_empty() {
            for j in (i..=100_000).step_by(i) {
                sieve[j].insert(i);
            }
        }
    }

    let mut on: HashSet<usize> = HashSet::new();
    let mut conflicts: HashMap<usize, usize> = HashMap::new();

    for _ in 0..m {
        let a = iter.next().unwrap().chars().next().unwrap();
        let b = iter.next().unwrap().parse::<usize>().unwrap();

        if a == '-' {
            if !on.contains(&b) {
                println!("Already off");
            } else {
                on.remove(&b);
                for &prime in &sieve[b] {
                    conflicts.remove(&prime);
                }
                println!("Success");
            }
        } else if a == '+' {
            if on.contains(&b) {
                println!("Already on");
            } else {
                let mut success = true;
                for &prime in &sieve[b] {
                    if let Some(&conflict_with) = conflicts.get(&prime) {
                        success = false;
                        println!("Conflict with {}", conflict_with);
                        break;
                    }
                }
                if success {
                    on.insert(b);
                    for &prime in &sieve[b] {
                        conflicts.insert(prime, b);
                    }
                    println!("Success");
                }
            }
        }
    }
}
