from kivy.app import App
from kivy.uix.boxlayout import BoxLayout
from kivy.uix.textinput import TextInput
from kivy.uix.button import Button
from kivy.uix.label import Label
from sympy import sympify, SympifyError
import os


class CalculatorLayout(BoxLayout):
    def __init__(self, **kwargs):
        super().__init__(orientation='vertical', **kwargs)

        self.display = TextInput(font_size=32, size_hint=(1, 0.2), multiline=False)
        self.add_widget(self.display)

        buttons = [
            ['7', '8', '9', '/'],
            ['4', '5', '6', '*'],
            ['1', '2', '3', '-'],
            ['0', '.', '=', '+']
        ]

        for row in buttons:
            h_layout = BoxLayout()
            for label in row:
                button = Button(text=label, font_size=24)
                button.bind(on_press=self.on_button_press)
                h_layout.add_widget(button)
            self.add_widget(h_layout)

        # Bottom row: Clear, History
        bottom_row = BoxLayout()
        clear_btn = Button(text='Clear', font_size=20)
        clear_btn.bind(on_press=self.clear_display)
        bottom_row.add_widget(clear_btn)

        history_btn = Button(text='History', font_size=20)
        history_btn.bind(on_press=self.show_history)
        bottom_row.add_widget(history_btn)

        self.history_label = Label(size_hint=(1, 0.5), text='', font_size=18)
        self.add_widget(bottom_row)
        self.add_widget(self.history_label)

    def on_button_press(self, instance):
        text = instance.text
        if text == '=':
            self.calculate_result()
        else:
            self.display.text += text

    def calculate_result(self):
        expression = self.display.text
        try:
            result = str(sympify(expression))
            self.display.text = result
            with open("Calculator.txt", "a") as file:
                file.write(f"{expression} = {result}\n")
        except SympifyError:
            self.display.text = "Invalid"

    def clear_display(self, instance):
        self.display.text = ""
        self.history_label.text = ""

    def show_history(self, instance):
        if os.path.exists("Calculator.txt"):
            with open("Calculator.txt", "r") as file:
                history = file.read()
                self.history_label.text = f"[History]\n{history}"
        else:
            self.history_label.text = "[No history found]"


class CalculatorApp(App):
    def build(self):
        return CalculatorLayout()


if __name__ == '__main__':
    CalculatorApp().run()
