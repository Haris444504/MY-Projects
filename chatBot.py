import random
import datetime

class ChatBot:
    def __init__(self, name=""):
        self.name = name
        self.username = ""
        self.intents = {
            "hi": "How are you? How can I help you?",
            "hello": "Hello! How can I assist you today?",
            "how are you": "I'm just a program, but thanks for asking!",
            "what's your name": "I am a chatbot created to assist you.",
            "what can you do": "I can help answer questions, provide information, and assist with various tasks.",
            "who created you": "I was created by Haris Saddique.",
            "what is your purpose": "My purpose is to assist and provide information to users like you.",
            "joke": "joke",  # flag to trigger random joke
            "date": "date",
            "time": "time",
            "weather": "I can't check the weather, but you can use a weather app or website.",
            "news": "I can't provide real-time news, but you can check news websites.",
            "quote": "The only limit to our realization of tomorrow is our doubts of today.",
            "bye": "Goodbye! Have a great day!",
            "thanks": "You're welcome! Ask me anything!",
            "help": "Sure! What do you need help with?",
            "default": "I'm sorry, I didn't understand that. Can you please rephrase?"
        }

    def greet_user(self):
        print(f"{self.name}: Hello! What's your name?")
        self.username = input("You: ")
        print(f"{self.name}: Nice to meet you, {self.username}. How can I assist you today?")

    def handle_input(self, message):
        response = self.get_response(message)

        if response == "joke":
            print(f"{self.name}: {self.get_random_joke()}")
        elif response == "date" or response == "time":
            print(f"{self.name}: The current date and time is {self.get_date_time()}")
        else:
            print(f"{self.name}: {response}")

    def get_response(self, message):
        msg = message.lower().strip()
        return self.intents.get(msg, self.intents["default"])

    def get_date_time(self):
        return datetime.datetime.now().strftime("%Y-%m-%d %H:%M:%S")

    def get_random_joke(self):
        jokes = [
            "Why don't scientists trust atoms? Because they make up everything!",
            "Why did the scarecrow win an award? Because he was outstanding in his field!",
            "I told my computer I needed a break, and now it won't stop sending me beach wallpapers.",
            "Parallel lines have so much in common. It’s a shame they’ll never meet.",
            "Why do we never tell secrets on a farm? Because the potatoes have eyes and the corn has ears!"
        ]
        return random.choice(jokes)

def main():
    bot = ChatBot("ChatPy")
    bot.greet_user()

    while True:
        user_input = input("You: ")
        if user_input.lower() == "exit":
            print("ChatBot: Goodbye! Have a great day!")
            break
        bot.handle_input(user_input)

if __name__ == "__main__":
    main()
