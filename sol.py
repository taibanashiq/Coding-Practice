import random

secret_number = random.randint(1, 100)

print("Welcome to the Number Guessing Game!")
print("I'm thinking of a number between 1 and 100")

attempts = 0

while True:
    try:
        user_input = input("Enter your guess: ")

        if user_input == "":
            print("❌ No input detected!")
            continue

        guess = int(user_input)
        attempts += 1

        if guess < secret_number:
            print("Too low! Try again.")
        elif guess > secret_number:
            print("Too high! Try again.")
        else:
            print(f"🎉 Congratulations! You guessed the number in {attempts} attempts.")
            break

    except EOFError:
        print("⚠️ Input not supported in this environment.")
        break
    except ValueError:
        print("❌ Please enter a valid number!")
