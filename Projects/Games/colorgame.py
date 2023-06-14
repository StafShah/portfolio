import tkinter as tk
import random

root = tk.Tk()
root.configure(background='white')
root.geometry("435x330+125+150")
header = tk.Label(root, text="What's That Color?", font=('Arial', 25), padx=50, pady=10, background='white')
header.grid(row=0)
frame = tk.Frame(root, background='white')
frame.grid(row=1)

colors = ['red', 'orange', 'yellow', 'green', 'blue', 'purple', 'black', 'white', 'brown', 'grey']
idxCount = 9


def input_changed(e, target, widgets):
    global idxCount
    global colors
    global curr_round
    entry_input = e.get()

    if entry_input == target:

        for widget in widgets:
            widget.destroy()
        idxCount -= 1
        new_round = colorSwitch(idxCount, curr_round.colors)
        curr_round = new_round
        curr_round.switch()


class colorSwitch:

    def __init__(self, idx, colors):
        self.idx = idx
        self.colors = colors

    def red_display(self):
        widgets = []
        canvas = tk.Canvas(frame, width=150, height=150)
        red_rectangle = canvas.create_rectangle(0, 0, 150, 150, fill='#FF0000', outline='#FF0000')
        canvas.pack()

        instruction_label = tk.Label(frame, text="Type the color below!", pady=10, background='white')
        instruction_label.pack()

        target = "red"

        check_var = tk.StringVar()
        check_var.trace("w", lambda name, index, mode, check_var=check_var: input_changed(check_var, target, widgets))
        e = tk.Entry(frame, textvariable=check_var)
        e.pack()

        widgets.extend([canvas, instruction_label, e])

    def orange_display(self):
        widgets = []
        canvas = tk.Canvas(frame, width=150, height=150)
        orange_rectangle = canvas.create_rectangle(0, 0, 150, 150, fill='#ff8c00', outline='#ff8c00')
        canvas.pack()

        instruction_label = tk.Label(frame, text="Type the color below!", pady=10, background='white')
        instruction_label.pack()

        target = "orange"

        check_var = tk.StringVar()
        check_var.trace("w", lambda name, index, mode, check_var=check_var: input_changed(check_var, target, widgets))
        e = tk.Entry(frame, textvariable=check_var)
        e.pack()

        widgets.extend([canvas, instruction_label, e])

    def yellow_display(self):
        widgets = []
        canvas = tk.Canvas(frame, width=150, height=150)
        yellow_rectangle = canvas.create_rectangle(0, 0, 150, 150, fill='#FFFF00', outline='#FFFF00')
        canvas.pack()

        instruction_label = tk.Label(frame, text="Type the color below!", pady=10, background='white')
        instruction_label.pack()

        target = "yellow"

        check_var = tk.StringVar()
        check_var.trace("w", lambda name, index, mode, check_var=check_var: input_changed(check_var, target, widgets))
        e = tk.Entry(frame, textvariable=check_var)
        e.pack()

        widgets.extend([canvas, instruction_label, e])

    def green_display(self):
        widgets = []
        canvas = tk.Canvas(frame, width=150, height=150)
        green_rectangle = canvas.create_rectangle(0, 0, 150, 150, fill='#00FF00', outline='#00FF00')
        canvas.pack()

        instruction_label = tk.Label(frame, text="Type the color below!", pady=10, background='white')
        instruction_label.pack()

        target = "green"

        check_var = tk.StringVar()
        check_var.trace("w", lambda name, index, mode, check_var=check_var: input_changed(check_var, target, widgets))
        e = tk.Entry(frame, textvariable=check_var)
        e.pack()

        widgets.extend([canvas, instruction_label, e])

    def blue_display(self):
        widgets = []
        canvas = tk.Canvas(frame, width=150, height=150)
        blue_rectangle = canvas.create_rectangle(0, 0, 150, 150, fill='#0000FF', outline='#0000FF')
        canvas.pack()

        instruction_label = tk.Label(frame, text="Type the color below!", pady=10, background='white')
        instruction_label.pack()

        target = "blue"

        check_var = tk.StringVar()
        check_var.trace("w", lambda name, index, mode, check_var=check_var: input_changed(check_var, target, widgets))
        e = tk.Entry(frame, textvariable=check_var)
        e.pack()

        widgets.extend([canvas, instruction_label, e])

    def purple_display(self):
        widgets = []
        canvas = tk.Canvas(frame, width=150, height=150)
        purple_rectangle = canvas.create_rectangle(0, 0, 150, 150, fill='#800080', outline='#800080')
        canvas.pack()

        instruction_label = tk.Label(frame, text="Type the color below!", pady=10, background='white')
        instruction_label.pack()

        target = "purple"

        check_var = tk.StringVar()
        check_var.trace("w", lambda name, index, mode, check_var=check_var: input_changed(check_var, target, widgets))
        e = tk.Entry(frame, textvariable=check_var)
        e.pack()

        widgets.extend([canvas, instruction_label, e])

    def black_display(self):
        widgets = []
        canvas = tk.Canvas(frame, width=150, height=150)
        black_rectangle = canvas.create_rectangle(0, 0, 150, 150, fill='#000000', outline='#000000')
        canvas.pack()

        instruction_label = tk.Label(frame, text="Type the color below!", pady=10, background='white')
        instruction_label.pack()

        target = "black"

        check_var = tk.StringVar()
        check_var.trace("w", lambda name, index, mode, check_var=check_var: input_changed(check_var, target, widgets))
        e = tk.Entry(frame, textvariable=check_var)
        e.pack()

        widgets.extend([canvas, instruction_label, e])

    def white_display(self):
        widgets = []
        canvas = tk.Canvas(frame, width=150, height=150)
        white_rectangle = canvas.create_rectangle(0, 0, 150, 150, fill='#FFFFFF', outline='#000000')
        canvas.pack()

        instruction_label = tk.Label(frame, text="Type the color below!", pady=10, background='white')
        instruction_label.pack()

        target = "white"

        check_var = tk.StringVar()
        check_var.trace("w", lambda name, index, mode, check_var=check_var: input_changed(check_var, target, widgets))
        e = tk.Entry(frame, textvariable=check_var)
        e.pack()

        widgets.extend([canvas, instruction_label, e])

    def brown_display(self):
        widgets = []
        canvas = tk.Canvas(frame, width=150, height=150)
        brown_rectangle = canvas.create_rectangle(0, 0, 150, 150, fill='#a52a2a', outline='#a52a2a')
        canvas.pack()

        instruction_label = tk.Label(frame, text="Type the color below!", pady=10, background='white')
        instruction_label.pack()

        target = "brown"

        check_var = tk.StringVar()
        check_var.trace("w", lambda name, index, mode, check_var=check_var: input_changed(check_var, target, widgets))
        e = tk.Entry(frame, textvariable=check_var)
        e.pack()

        widgets.extend([canvas, instruction_label, e])

    def grey_display(self):
        widgets = []
        canvas = tk.Canvas(frame, width=150, height=150)
        grey_rectangle = canvas.create_rectangle(0, 0, 150, 150, fill='#808080', outline='#808080')
        canvas.pack()

        instruction_label = tk.Label(frame, text="Type the color below!", pady=10, background='white')
        instruction_label.pack()

        target = "grey"

        check_var = tk.StringVar()
        check_var.trace("w", lambda name, index, mode, check_var=check_var: input_changed(check_var, target, widgets))
        e = tk.Entry(frame, textvariable=check_var)
        e.pack()

        widgets.extend([canvas, instruction_label, e])

    def switch(self):
        if len(colors) == 1:
            num = 0
        elif self.idx > 0:
            num = random.randrange(0, self.idx, 1)
        else:
            num = None
            frame.destroy()
            win_label = tk.Label(root, text="You Win!", font=('Arial', 25), pady=10, fg='yellow', bg="white")
            win_label.grid(row=1)
            return

        if colors[num] == 'red':
            self.red_display()
        elif colors[num] == 'orange':
            self.orange_display()
        elif colors[num] == 'yellow':
            self.yellow_display()
        elif colors[num] == 'green':
            self.green_display()
        elif colors[num] == 'blue':
            self.blue_display()
        elif colors[num] == 'purple':
            self.purple_display()
        elif colors[num] == 'black':
            self.black_display()
        elif colors[num] == 'white':
            self.white_display()
        elif colors[num] == 'brown':
            self.brown_display()
        elif colors[num] == 'grey':
            self.grey_display()
        self.colors.pop(num)


exit_button = tk.Button(root, fg='red', bg='white', text="Exit Game", command=root.destroy)
exit_button.grid(row=5, pady=5)

curr_round = colorSwitch(idxCount, colors)
curr_round.switch()

root.mainloop()
