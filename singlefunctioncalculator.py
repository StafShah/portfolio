from tkinter import *

root = Tk()
root.title("Arithmetic Calculator")

negative_button_pressed = False


def number_input(number):
    input_bar.insert(END, str(number))
    return None


def add():
    global add_button_pressed
    global subtract_button_pressed
    global multiply_button_pressed
    global divide_button_pressed
    global first_number
    add_button_pressed = True
    subtract_button_pressed = False
    multiply_button_pressed = False
    divide_button_pressed = False
    first_num = input_bar.get()
    first_number = float(first_num)
    input_bar.delete(0, END)


def subtract():
    global add_button_pressed
    global subtract_button_pressed
    global multiply_button_pressed
    global divide_button_pressed
    global first_number
    add_button_pressed = False
    subtract_button_pressed = True
    multiply_button_pressed = False
    divide_button_pressed = False
    first_num = input_bar.get()
    first_number = float(first_num)
    input_bar.delete(0, END)


def multiply():
    global add_button_pressed
    global subtract_button_pressed
    global multiply_button_pressed
    global divide_button_pressed
    global first_number
    add_button_pressed = False
    subtract_button_pressed = False
    multiply_button_pressed = True
    divide_button_pressed = False
    first_num = input_bar.get()
    first_number = float(first_num)
    input_bar.delete(0, END)


def divide():
    global add_button_pressed
    global subtract_button_pressed
    global multiply_button_pressed
    global divide_button_pressed
    global first_number
    add_button_pressed = False
    subtract_button_pressed = False
    multiply_button_pressed = False
    divide_button_pressed = True
    first_num = input_bar.get()
    first_number = float(first_num)
    input_bar.delete(0, END)


def equal():
    global add_button_pressed
    global subtract_button_pressed
    global multiply_button_pressed
    global divide_button_pressed
    global second_number
    secondnum = input_bar.get()
    second_number = float(secondnum)
    if second_number == None:
        input_bar.delete(0, END)
        input_bar.insert(0, str(first_number))
    else:
        input_bar.delete(0, END)
        if add_button_pressed is True:
            input_bar.insert(0, str(first_number + float(second_number)))
        elif subtract_button_pressed is True:
            input_bar.insert(0, str(first_number - float(second_number)))
        elif multiply_button_pressed is True:
            input_bar.insert(0, str(first_number * float(second_number)))
        elif divide_button_pressed is True:
            try:
                input_bar.insert(0, str(first_number / float(second_number)))
            except ZeroDivisionError:
                input_bar.insert(0, "ERROR")
    add_button_pressed = False
    subtract_button_pressed = False
    multiply_button_pressed = False
    divide_button_pressed = False


def decimal():
    input_bar.insert(END, ".")


def negative():
    global negative_button_pressed
    if negative_button_pressed is False:
        negative_button_pressed = True
        input_bar.insert(0, "-")
    else:
        negative_button_pressed = False
        input_bar.delete(0, 1)


def clear_entry():
    input_bar.delete(0, END)
    return None


def all_clear():
    global add_button_pressed
    global subtract_button_pressed
    global multiply_button_pressed
    global divide_button_pressed
    global first_number
    global second_number
    del first_number
    del second_number
    add_button_pressed = False
    subtract_button_pressed = False
    multiply_button_pressed = False
    divide_button_pressed = False
    input_bar.delete(0, END)
    return None


input_bar = Entry(root, font=('Arial', 30), borderwidth=5)
input_bar.grid(row=0, columnspan=4, padx=10, pady=10)

add_button = Button(root, padx=49, pady=49, text="+", command=add, justify=CENTER)
add_button.grid(row=4, column=3)

subtract_button = Button(root, padx=50, pady=50, text="-", command=subtract, justify=CENTER)
subtract_button.grid(row=3, column=3)

multiply_button = Button(root, padx=50, pady=50, text="x", command=multiply, justify=CENTER)
multiply_button.grid(row=2, column=3)

divide_button = Button(root, padx=49, pady=50, text="÷", command=divide, justify=CENTER)
divide_button.grid(row=1, column=3)

equal_button = Button(root, padx=49, pady=50, text="=", command=equal, justify=CENTER)
equal_button.grid(row=5, column=3)

decimal_button = Button(root, padx=52, pady=50, text=".", command=decimal, justify=CENTER)
decimal_button.grid(row=5, column=2)

negative_button = Button(root, padx=44, pady=50, text="+/-", command=negative, justify=CENTER)
negative_button.grid(row=1, column=2)

ce_button = Button(root, padx=46, pady=50, text="CE", command=clear_entry, justify=CENTER)
ce_button.grid(row=1, column=0)

ac_button = Button(root, padx=45, pady=50, text="AC", command=all_clear, justify=CENTER)
ac_button.grid(row=1, column=1)

buttons = []

for digit in range(0, 10):
    if digit == 0:
        button = Button(root, padx=108, pady=50, text=str(digit), command=lambda digit=digit: number_input(digit),
                        justify=CENTER)
        button.grid(row=5, column=0, columnspan=2)
        buttons.append(button)
    elif digit <= 3:
        button = Button(root, padx=50, pady=50, text=str(digit), command=lambda digit=digit: number_input(digit),
                        justify=CENTER)
        button.grid(row=4, column=(digit - 1))
        buttons.append(button)
    elif digit <= 6:
        button = Button(root, padx=50, pady=50, text=str(digit), command=lambda digit=digit: number_input(digit),
                        justify=CENTER)
        button.grid(row=3, column=(digit - 4))
        buttons.append(button)
    else:
        button = Button(root, padx=50, pady=50, text=str(digit), command=lambda digit=digit: number_input(digit),
                        justify=CENTER)
        button.grid(row=2, column=(digit - 7))
        buttons.append(button)

root.mainloop()
