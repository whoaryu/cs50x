from cs50 import get_float

change_owed_in_dollars = min_coins_needed = 0


def main() -> None:
    global change_owed_in_dollars, min_coins_needed
    while True:
        change_owed_in_dollars = get_float("Change owed: ")
        if change_owed_in_dollars > 0:
            break
    for coin_type in [25, 10, 5, 1]:
        calculate_min_coins_needed_for_the_change_owed(coin_type)
    print(min_coins_needed)


def calculate_min_coins_needed_for_the_change_owed(coin_type: int) -> None:
    global change_owed_in_dollars, min_coins_needed
    change_owed_in_cents = int(change_owed_in_dollars * 100)
    if change_owed_in_cents / coin_type >= 1:
        coins_quantity = int(change_owed_in_cents / coin_type)
        min_coins_needed += coins_quantity
        change_owed_in_cents -= coins_quantity * coin_type
        change_owed_in_dollars = change_owed_in_cents / 100


main()
