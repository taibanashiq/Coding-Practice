import tkinter as tk
import random
import sys

# ------------------ DATA ------------------
words = {
    "Aberration": "A departure from what is normal",
    "Capitulate": "To surrender",
    "Debilitate": "To weaken",
    "Enigma": "A mystery",
    "Fervent": "Having intense passion",
    "Lucid": "Clear and easy to understand",
    "Obsolete": "No longer in use",
    "Resilient": "Able to recover quickly"
}

# ------------------ CLI VERSION -------------
def run_cli():
    print("Vocabulary Trainer (CLI Mode)")
    print("--------------------------------")
    
    score = 0
    word_list = list(words.keys())
    random.shuffle(word_list)

    # Learn Mode
    print("\n📖 Learn Words:")
    for word, meaning in words.items():
        print(f"{word} : {meaning}")

    # Quiz Mode
    print("\n🧠 Quiz Mode:")
    for i in range(3):
        word = word_list[i]
        print(f"\nWhat is the meaning of '{word}'?")
        ans = input("Your answer: ").strip().lower()

        if ans in words[word].lower():
            print("✅ Correct!")
            score += 1
        else:
            print(f"❌ Wrong! Answer: {words[word]}")

    print(f"\n🎯 Final Score: {score}/3")


# ------------------ GUI VERSION -------------
def run_gui():
    score = 0
    current_word = ""

    def show_word():
        word = random.choice(list(words.keys()))
        label_word.config(text=word)
        label_meaning.config(text=words[word])

    def start_quiz():
        nonlocal current_word
        current_word = random.choice(list(words.keys()))
        correct = words[current_word]

        # Generate options
        options = [correct]
        while len(options) < 4:
            opt = random.choice(list(words.values()))
            if opt not in options:
                options.append(opt)

        random.shuffle(options)

        label_question.config(text=f"What is the meaning of '{current_word}'?")

        for i in range(4):
            option_buttons[i].config(text=options[i], state="normal")

        result_label.config(text="")

    def check_answer(selected):
        nonlocal score

        if current_word == "":
            result_label.config(text="⚠ Start quiz first!")
            return

        correct = words[current_word]

        if selected == correct:
            score += 1
            result_label.config(text="✅ Correct!")
        else:
            result_label.config(text=f"❌ Wrong!\nAnswer: {correct}")

        score_label.config(text=f"Score: {score}")

        for btn in option_buttons:
            btn.config(state="disabled")

    # GUI Setup
    root = tk.Tk()
    root.title("Vocabulary Trainer")
    root.geometry("500x550")
    root.config(bg="#eef5ff")

    tk.Label(root, text="Vocabulary Trainer", font=("Arial", 18, "bold"),
             bg="#eef5ff").pack(pady=10)

    # Learn Section
    tk.Button(root, text="Learn Word", command=show_word).pack(pady=5)

    label_word = tk.Label(root, text="", font=("Arial", 14, "bold"), bg="#eef5ff")
    label_word.pack()

    label_meaning = tk.Label(root, text="", bg="#eef5ff")
    label_meaning.pack()

    # Quiz Section
    tk.Button(root, text="Start Quiz", command=start_quiz).pack(pady=10)

    label_question = tk.Label(root, text="", wraplength=400, bg="#eef5ff")
    label_question.pack()

    option_buttons = []
    for i in range(4):
        btn = tk.Button(
            root,
            text="",
            width=50,
            command=lambda x=i: check_answer(option_buttons[x].cget("text"))
        )
        btn.pack(pady=3)
        option_buttons.append(btn)

    result_label = tk.Label(root, text="", bg="#eef5ff")
    result_label.pack(pady=5)

    score_label = tk.Label(root, text="Score: 0", font=("Arial", 12, "bold"),
                           bg="#eef5ff")
    score_label.pack(pady=10)

    root.mainloop()


# ------------------ AUTO DETECT ----------
try:
    root = tk.Tk()
    root.destroy()
    run_gui()
except:
    print("⚠ GUI not supported. Switching to CLI mode...\n")
    run_cli()