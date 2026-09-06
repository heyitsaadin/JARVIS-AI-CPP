# JARVIS-AI-CPP

A C++ command-line assistant featuring user authentication, file-based data handling, and heuristic response logic. My first major milestone in software development.

## Features

- **User registration & login** — credentials are stored locally in `users.txt`
- **Canned Q&A responses** — greetings, small talk, and basic questions are matched from `responses.txt` (auto-generated on startup)
- **Time & date queries** — ask "what time is it" or "what day is it"
- **Simple arithmetic** — supports basic `+` and `-` expressions (e.g. `what is 4 + 5`)
- **Typewriter-style output** — responses are printed character-by-character for a more conversational feel

## Requirements

- A C++ compiler with C++11 support or later (e.g. `g++`)
- POSIX environment (uses `unistd.h` for `usleep`, so Linux/macOS or WSL on Windows)

## Build

```bash
g++ -o jarvis main.cpp
```

## Run

```bash
./jarvis
```

On startup you'll be prompted to register or log in:

```
enter 1 for Register
enter 2 for Login
Choice: 1
Username: alex
Password: ********
Registered successfully!
```

Log back in with the same credentials, then chat with the assistant. Type `exit` to quit.

### Example interaction

```
You: hello
AI: Hello! How are you doing?

You: what is 4 + 5
AI: 4.000000 + 5.000000 is 9.000000

You: what time is it
AI: The time is 3:45 PM
```

## Notes

- `users.txt` and `responses.txt` are created/updated in the working directory at runtime — no setup needed beforehand.
- Passwords are stored in plain text; this project is a learning exercise and **not intended for production use**.

---

This is a small project that ive designed and i know the features isn't alot and impressive but this is the first ever code ive written so it deserves a special place in my life also ive redesigned this and implemented a web version which is far better than this
