use std::io;

fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let t: usize = input.trim().parse().unwrap();

    for _ in 0..t {
        input.clear();
        io::stdin().read_line(&mut input).unwrap();
        let n: usize = input.trim().parse().unwrap();

        let mut ishaan_white = 0;
        let mut ishaan_black = 0;
        let mut sid_white = 0;
        let mut sid_black = 0;

        let mut step = 1;
        let mut current_player = 0;
        let mut cards_remaining = n;
        let mut color = 0;

        while cards_remaining > 0 {
            let cards_to_deal = std::cmp::min(step, cards_remaining);
            let white_cards = (cards_to_deal + 1 - color) / 2;
            let black_cards = cards_to_deal - white_cards;

            if current_player == 0 {
                ishaan_white += white_cards;
                ishaan_black += black_cards;
            } else {
                sid_white += white_cards;
                sid_black += black_cards;
            }

            cards_remaining -= cards_to_deal;
            color = (color + cards_to_deal) % 2;
            step += 1;
            current_player = (current_player + 1) % 2;
            if step % 2 == 1 {
                current_player = (current_player + 1) % 2;
            }
        }

        println!(
            "{} {} {} {}",
            ishaan_white, ishaan_black, sid_white, sid_black
        );
    }
}
