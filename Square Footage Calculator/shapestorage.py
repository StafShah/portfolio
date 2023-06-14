import tkinter as tk
from abc import ABC, abstractmethod
from math import *
from PIL import ImageTk, Image


# Shape Instances
class Shape(ABC):

    def __init__(self):
        pass

    @abstractmethod
    def calculate(self):
        pass


class Square(Shape):

    def __init__(self, side):
        super().__init__()
        self.__side = side

    def calculate(self):
        return int(pow(self.__side, 2))


class Rectangle(Shape):

    def __init__(self, side1, side2):
        super().__init__()
        self.__side1 = side1
        self.__side2 = side2

    def calculate(self):
        return int(self.__side1 * self.__side2)


class Triangle(Shape):

    def __init__(self, side1, side2):
        super().__init__()
        self.__side1 = side1
        self.__side2 = side2

    def calculate(self):
        return int(self.__side1 * self.__side2 * 0.5)


class Circle(Shape):

    def __init__(self, side1):
        super().__init__()
        self.__side1 = side1

    def calculate(self):
        return int(pow(self.__side1, 2) * pi)


class HalfCircle:

    def __init__(self, side1):
        super().__init__()
        self.__side1 = side1

    def calculate(self):
        return int(pow(self.__side1, 2) * pi / 2)


class Trapezoid(Shape):

    def __init__(self, side1, side2, side3):
        super().__init__()
        self.__side1 = side1
        self.__side2 = side2
        self.__side3 = side3

    def calculate(self):
        square_sum = self.__side1 + self.__side2
        quotient = square_sum / 2
        return int(quotient * self.__side3)


class L_Shape(Shape):

    def __init__(self, side1, side2, side3, side4):
        super().__init__()
        self.__side1 = side1
        self.__side2 = side2
        self.__side3 = side3
        self.__side4 = side4

    def calculate(self):
        rectangle1 = self.__side1 * self.__side2
        rectangle2 = self.__side3 * self.__side4
        return int(rectangle1 + rectangle2)


# Instances for GUIs
class Base:

    def __init__(self, frame, dimensions):
        self.clear_frame(frame)
        self.side_label_list = []
        self.ft_label_list = []
        self.in_label_list = []
        self.ft_list = []
        self.in_list = []
        for _ in range(dimensions):
            if dimensions == 1:
                self.side_label_list.append(tk.Label(frame, text="Side:", bg="#ffffff"))
            else:
                self.side_label_list.append(tk.Label(frame, text="Side " + str(_ + 1) + ":", bg="#ffffff"))
            self.ft_label_list.append(tk.Label(frame, text="FT", bg='#ffffff'))
            self.in_label_list.append(tk.Label(frame, text="IN", bg='#ffffff'))
        for _ in range(dimensions):
            self.ft_list.append(tk.Entry(frame, bg='#ededed'))
            self.in_list.append(tk.Entry(frame, bg='#ededed'))
        for bar in self.ft_list:
            bar.insert(0, str(0))
        for bar in self.in_list:
            bar.insert(0, str(0))

    @staticmethod
    def clear_frame(frame):
        for widgets in frame.winfo_children():
            widgets.destroy()

    def grid(self):
        pass


class Square_Display(Base):

    def __init__(self, frame):
        self.dimensions = 1
        super().__init__(frame, self.dimensions)
        self.square_frame_header = tk.Label(frame, text="Square Estimate", font=("Arial", 16), bg="#ffffff",
                                            justify=tk.CENTER)
        self.square_feet_answer_label = tk.Label(frame, text="FT", bg='#ffffff')
        self.square_inches_answer_label = tk.Label(frame, text="IN", bg='#ffffff')
        self.square_price_per_square_foot_label_1 = tk.Label(frame, text="Price:                    $",
                                                             bg='#ffffff')
        self.square_price_per_square_foot_label_2 = tk.Label(frame, text="per Square Foot", bg='#ffffff')
        self.square_price_per_square_foot_label_3 = tk.Label(frame, text="Total:                    $",
                                                             bg='#ffffff')
        self.square_area_label = tk.Label(frame, text="Area:", bg="#ffffff")
        self.square_img = Image.open(r"C:\Users\Mustafa Shah\PycharmProjects\Projects\images\square.png")
        self.square_img.resize((400, 320))
        self.square_image = ImageTk.PhotoImage(self.square_img)
        self.square_image_label = tk.Label(frame, width=400, height=320, image=self.square_image, anchor=tk.CENTER)
        self.square_price_input_bar = tk.Entry(frame, bg='#ededed', width=10)
        self.square_price_input_bar.insert(0, str(0.00))
        self.square_calculate_button = tk.Button(frame, text="Calculate", bg="#ededed", width=20,
                                                 justify=tk.CENTER,
                                                 command=self.execute)
        self.square_feet_answer_bar = tk.Entry(frame, state=tk.DISABLED, bg='#ededed')
        self.square_inches_answer_bar = tk.Entry(frame, state=tk.DISABLED, bg='#ededed')
        self.price_answer_bar = tk.Entry(frame, state=tk.DISABLED, bg='#ededed', width=10)
        self.grid()

    def grid(self):
        self.square_frame_header.grid(column=0, columnspan=7, row=1, pady=5)
        for d in range(self.dimensions):
            self.side_label_list[d].grid(column=0, row=3 + d)
            self.ft_label_list[d].grid(column=2, row=3 + d)
            self.in_label_list[d].grid(column=4, row=3 + d, padx=40)
        self.square_feet_answer_label.grid(column=2, row=6)
        self.square_inches_answer_label.grid(column=4, row=6)
        self.square_price_per_square_foot_label_1.grid(column=1, row=4)
        self.square_price_per_square_foot_label_2.grid(column=3, row=4, pady=20)
        self.square_price_per_square_foot_label_3.grid(column=1, row=7)
        self.square_area_label.grid(column=0, row=6)
        self.square_image_label.grid(column=0, row=2, columnspan=5, padx=10, pady=5)
        for d in range(self.dimensions):
            self.ft_list[d].grid(column=1, row=3, padx=20, pady=10)
            self.in_list[d].grid(column=3, row=3, pady=10)
        self.square_price_input_bar.grid(column=2, row=4)
        self.square_calculate_button.grid(column=1, row=5, columnspan=3)
        self.square_feet_answer_bar.grid(column=1, row=6, pady=50)
        self.square_inches_answer_bar.grid(column=3, row=6, pady=50)
        self.price_answer_bar.grid(column=2, row=7, pady=10)

    def execute(self):
        answer_bars = []
        feet_list = [int(t.get()) for t in self.ft_list]
        inches_list = [int(t.get()) for t in self.in_list]
        for b in [self.square_feet_answer_bar, self.square_inches_answer_bar, self.price_answer_bar]:
            answer_bars.append(b)
        rate = float(self.square_price_input_bar.get())
        inches_sum = convert_to_inches(feet_list[0], inches_list[0])
        variable_square = Square(inches_sum)
        for bar in answer_bars:
            bar.config(state=tk.NORMAL)
            bar.delete(0, tk.END)
        self.square_feet_answer_bar.insert(0, string=str(variable_square.calculate() // 144))
        self.square_inches_answer_bar.insert(0, string=str(round(variable_square.calculate() % 144 / 12, 2)))
        self.price_answer_bar.insert(0, string=str(round(variable_square.calculate() / 144 * rate, 2)))
        for bar in answer_bars:
            bar.config(state=tk.DISABLED)


class Rectangle_Display(Base):

    def __init__(self, frame):
        self.dimensions = 2
        super().__init__(frame, self.dimensions)
        self.frame_header = tk.Label(frame, text="Rectangle Estimate", font=("Arial", 16), bg="#ffffff",
                                     justify=tk.CENTER)
        self.square_feet_label_2 = tk.Label(frame, text="FT", bg='#ffffff')
        self.square_inches_label_2 = tk.Label(frame, text="IN", bg='#ffffff')
        self.square_price_per_square_foot_label_1 = tk.Label(frame, text="Price:                    $",
                                                             bg='#ffffff')
        self.square_price_per_square_foot_label_2 = tk.Label(frame, text="per Square Foot", bg='#ffffff')
        self.square_price_per_square_foot_label_3 = tk.Label(frame, text="Total:                    $",
                                                             bg='#ffffff')
        self.square_area_label = tk.Label(frame, text="Area:", bg="#ffffff")
        self.square_img = Image.open(r"C:\Users\Mustafa Shah\PycharmProjects\Projects\images\rectangle.png")
        self.square_img.resize((400, 320))
        self.square_image = ImageTk.PhotoImage(self.square_img)
        self.square_image_label = tk.Label(frame, width=400, height=320, image=self.square_image, anchor=tk.CENTER)
        self.square_price_input_bar = tk.Entry(frame, bg='#ededed', width=10)
        self.square_price_input_bar.insert(0, str(0.00))
        self.square_calculate_button = tk.Button(frame, text="Calculate", bg="#ededed", width=20,
                                                 justify=tk.CENTER,
                                                 command=self.execute)
        self.square_feet_answer_bar = tk.Entry(frame, state=tk.DISABLED, bg='#ededed')
        self.square_inches_answer_bar = tk.Entry(frame, state=tk.DISABLED, bg='#ededed')
        self.price_answer_bar = tk.Entry(frame, state=tk.DISABLED, bg='#ededed', width=10)
        self.grid()

    def grid(self):
        self.frame_header.grid(column=0, columnspan=7, row=1, pady=5)
        for d in range(self.dimensions):
            self.side_label_list[d].grid(column=0, row=3 + d)
            self.ft_label_list[d].grid(column=2, row=3 + d)
            self.in_label_list[d].grid(column=4, row=3 + d, padx=40)
        self.square_feet_label_2.grid(column=2, row=7)
        self.square_inches_label_2.grid(column=4, row=7)
        self.square_price_per_square_foot_label_1.grid(column=1, row=5)
        self.square_price_per_square_foot_label_2.grid(column=3, row=5, pady=20)
        self.square_price_per_square_foot_label_3.grid(column=1, row=8)
        self.square_area_label.grid(column=0, row=7)
        self.square_image_label.grid(column=0, row=2, columnspan=5, padx=10, pady=5)
        for d in range(self.dimensions):
            self.ft_list[d].grid(column=1, row=3 + d, padx=20, pady=10)
            self.in_list[d].grid(column=3, row=3 + d, pady=10)
        self.square_price_input_bar.grid(column=2, row=5)
        self.square_calculate_button.grid(column=1, row=6, columnspan=3)
        self.square_feet_answer_bar.grid(column=1, row=7, pady=50)
        self.square_inches_answer_bar.grid(column=3, row=7, pady=50)
        self.price_answer_bar.grid(column=2, row=8, pady=10)

    def execute(self):
        answer_bars = []
        inches_sum_list = []
        feet_list = [int(t.get()) for t in self.ft_list]
        inches_list = [int(t.get()) for t in self.in_list]
        for b in [self.square_feet_answer_bar, self.square_inches_answer_bar, self.price_answer_bar]:
            answer_bars.append(b)
        rate = float(self.square_price_input_bar.get())
        for _ in range(self.dimensions):
            inches_sum = convert_to_inches(feet_list[_], inches_list[_])
            inches_sum_list.append(inches_sum)
        variable_rectangle = Rectangle(inches_sum_list[0], inches_sum_list[1])
        for bar in answer_bars:
            bar.config(state=tk.NORMAL)
            bar.delete(0, tk.END)
        self.square_feet_answer_bar.insert(0, string=str(variable_rectangle.calculate() // 144))
        self.square_inches_answer_bar.insert(0, string=str(round(variable_rectangle.calculate() % 144 / 12, 2)))
        self.price_answer_bar.insert(0, string=str(round(variable_rectangle.calculate() / 144 * rate, 2)))
        for bar in answer_bars:
            bar.config(state=tk.DISABLED)


class Triangle_Display(Base):

    def __init__(self, frame):
        self.dimensions = 2
        super().__init__(frame, self.dimensions)
        self.frame_header = tk.Label(frame, text="Triangle Estimate", font=("Arial", 16), bg="#ffffff",
                                     justify=tk.CENTER)
        self.square_feet_label_2 = tk.Label(frame, text="FT", bg='#ffffff')
        self.square_inches_label_2 = tk.Label(frame, text="IN", bg='#ffffff')
        self.square_price_per_square_foot_label_1 = tk.Label(frame, text="Price:                    $",
                                                             bg='#ffffff')
        self.square_price_per_square_foot_label_2 = tk.Label(frame, text="per Square Foot", bg='#ffffff')
        self.square_price_per_square_foot_label_3 = tk.Label(frame, text="Total:                    $",
                                                             bg='#ffffff')
        self.square_area_label = tk.Label(frame, text="Area:", bg="#ffffff")
        self.square_img = Image.open(r"C:\Users\Mustafa Shah\PycharmProjects\Projects\images\triangle.png")
        self.square_img.resize((400, 320))
        self.square_image = ImageTk.PhotoImage(self.square_img)
        self.square_image_label = tk.Label(frame, width=400, height=320, image=self.square_image, anchor=tk.CENTER)
        self.square_price_input_bar = tk.Entry(frame, bg='#ededed', width=10)
        self.square_price_input_bar.insert(0, str(0.00))
        self.square_calculate_button = tk.Button(frame, text="Calculate", bg="#ededed", width=20,
                                                 justify=tk.CENTER,
                                                 command=self.execute)
        self.square_feet_answer_bar = tk.Entry(frame, state=tk.DISABLED, bg='#ededed')
        self.square_inches_answer_bar = tk.Entry(frame, state=tk.DISABLED, bg='#ededed')
        self.price_answer_bar = tk.Entry(frame, state=tk.DISABLED, bg='#ededed', width=10)
        self.grid()

    def grid(self):
        self.frame_header.grid(column=0, columnspan=7, row=1, pady=5)
        for d in range(self.dimensions):
            self.side_label_list[d].grid(column=0, row=3 + d)
            self.ft_label_list[d].grid(column=2, row=3 + d)
            self.in_label_list[d].grid(column=4, row=3 + d, padx=40)
        self.square_feet_label_2.grid(column=2, row=7)
        self.square_inches_label_2.grid(column=4, row=7)
        self.square_price_per_square_foot_label_1.grid(column=1, row=5)
        self.square_price_per_square_foot_label_2.grid(column=3, row=5, pady=20)
        self.square_price_per_square_foot_label_3.grid(column=1, row=8)
        self.square_area_label.grid(column=0, row=7)
        self.square_image_label.grid(column=0, row=2, columnspan=5, padx=10, pady=5)
        for d in range(self.dimensions):
            self.ft_list[d].grid(column=1, row=3 + d, padx=20, pady=10)
            self.in_list[d].grid(column=3, row=3 + d, pady=10)
        self.square_price_input_bar.grid(column=2, row=5)
        self.square_calculate_button.grid(column=1, row=6, columnspan=3)
        self.square_feet_answer_bar.grid(column=1, row=7, pady=50)
        self.square_inches_answer_bar.grid(column=3, row=7, pady=50)
        self.price_answer_bar.grid(column=2, row=8, pady=10)

    def execute(self):
        answer_bars = []
        inches_sum_list = []
        feet_list = [int(t.get()) for t in self.ft_list]
        inches_list = [int(t.get()) for t in self.in_list]
        for b in [self.square_feet_answer_bar, self.square_inches_answer_bar, self.price_answer_bar]:
            answer_bars.append(b)
        rate = float(self.square_price_input_bar.get())
        for _ in range(self.dimensions):
            inches_sum = convert_to_inches(feet_list[_], inches_list[_])
            inches_sum_list.append(inches_sum)
        variable_triangle = Triangle(inches_sum_list[0], inches_sum_list[1])
        for bar in answer_bars:
            bar.config(state=tk.NORMAL)
            bar.delete(0, tk.END)
        self.square_feet_answer_bar.insert(0, string=str(variable_triangle.calculate() // 144))
        self.square_inches_answer_bar.insert(0, string=str(round(variable_triangle.calculate() % 144 / 12, 2)))
        self.price_answer_bar.insert(0, string=str(round(variable_triangle.calculate() / 144 * rate, 2)))
        for bar in answer_bars:
            bar.config(state=tk.DISABLED)


class Circle_Display(Base):

    def __init__(self, frame):
        self.dimensions = 1
        super().__init__(frame, self.dimensions)
        self.frame_header = tk.Label(frame, text="Circle Estimate", font=("Arial", 16), bg="#ffffff",
                                     justify=tk.CENTER)
        self.square_feet_label_2 = tk.Label(frame, text="FT", bg='#ffffff')
        self.square_inches_label_2 = tk.Label(frame, text="IN", bg='#ffffff')
        self.square_price_per_square_foot_label_1 = tk.Label(frame, text="Price:                    $",
                                                             bg='#ffffff')
        self.square_price_per_square_foot_label_2 = tk.Label(frame, text="per Square Foot", bg='#ffffff')
        self.square_price_per_square_foot_label_3 = tk.Label(frame, text="Total:                    $",
                                                             bg='#ffffff')
        self.square_area_label = tk.Label(frame, text="Area:", bg="#ffffff")
        self.square_img = Image.open(r"C:\Users\Mustafa Shah\PycharmProjects\Projects\images\circle.png")
        self.square_img.resize((400, 320))
        self.square_image = ImageTk.PhotoImage(self.square_img)
        self.square_image_label = tk.Label(frame, width=400, height=320, image=self.square_image, anchor=tk.CENTER)
        self.square_price_input_bar = tk.Entry(frame, bg='#ededed', width=10)
        self.square_price_input_bar.insert(0, str(0.00))
        self.square_calculate_button = tk.Button(frame, text="Calculate", bg="#ededed", width=20,
                                                 justify=tk.CENTER,
                                                 command=self.execute)
        self.square_feet_answer_bar = tk.Entry(frame, state=tk.DISABLED, bg='#ededed')
        self.square_inches_answer_bar = tk.Entry(frame, state=tk.DISABLED, bg='#ededed')
        self.price_answer_bar = tk.Entry(frame, state=tk.DISABLED, bg='#ededed', width=10)
        self.grid()

    def grid(self):
        self.frame_header.grid(column=0, columnspan=7, row=1, pady=5)
        for d in range(self.dimensions):
            self.side_label_list[d].grid(column=0, row=3 + d)
            self.ft_label_list[d].grid(column=2, row=3 + d)
            self.in_label_list[d].grid(column=4, row=3 + d, padx=40)
        self.square_feet_label_2.grid(column=2, row=7)
        self.square_inches_label_2.grid(column=4, row=7)
        self.square_price_per_square_foot_label_1.grid(column=1, row=5)
        self.square_price_per_square_foot_label_2.grid(column=3, row=5, pady=20)
        self.square_price_per_square_foot_label_3.grid(column=1, row=8)
        self.square_area_label.grid(column=0, row=7)
        self.square_image_label.grid(column=0, row=2, columnspan=5, padx=10, pady=5)
        for d in range(self.dimensions):
            self.ft_list[d].grid(column=1, row=3 + d, padx=20, pady=10)
            self.in_list[d].grid(column=3, row=3 + d, pady=10)
        self.square_price_input_bar.grid(column=2, row=5)
        self.square_calculate_button.grid(column=1, row=6, columnspan=3)
        self.square_feet_answer_bar.grid(column=1, row=7, pady=50)
        self.square_inches_answer_bar.grid(column=3, row=7, pady=50)
        self.price_answer_bar.grid(column=2, row=8, pady=10)

    def execute(self):
        answer_bars = []
        inches_sum_list = []
        feet_list = [int(t.get()) for t in self.ft_list]
        inches_list = [int(t.get()) for t in self.in_list]
        for b in [self.square_feet_answer_bar, self.square_inches_answer_bar, self.price_answer_bar]:
            answer_bars.append(b)
        rate = float(self.square_price_input_bar.get())
        for _ in range(self.dimensions):
            inches_sum = convert_to_inches(feet_list[_], inches_list[_])
            inches_sum_list.append(inches_sum)
        variable_circle = Circle(inches_sum_list[0])
        for bar in answer_bars:
            bar.config(state=tk.NORMAL)
            bar.delete(0, tk.END)
        self.square_feet_answer_bar.insert(0, string=str(variable_circle.calculate() // 144))
        self.square_inches_answer_bar.insert(0, string=str(round(variable_circle.calculate() % 144 / 12, 2)))
        self.price_answer_bar.insert(0, string=str(round(variable_circle.calculate() / 144 * rate, 2)))
        for bar in answer_bars:
            bar.config(state=tk.DISABLED)


class Dome_Display(Base):

    def __init__(self, frame):
        self.dimensions = 1
        super().__init__(frame, self.dimensions)
        self.frame_header = tk.Label(frame, text="Dome Estimate", font=("Arial", 16), bg="#ffffff",
                                     justify=tk.CENTER)
        self.square_feet_label_2 = tk.Label(frame, text="FT", bg='#ffffff')
        self.square_inches_label_2 = tk.Label(frame, text="IN", bg='#ffffff')
        self.square_price_per_square_foot_label_1 = tk.Label(frame, text="Price:                    $",
                                                             bg='#ffffff')
        self.square_price_per_square_foot_label_2 = tk.Label(frame, text="per Square Foot", bg='#ffffff')
        self.square_price_per_square_foot_label_3 = tk.Label(frame, text="Total:                    $",
                                                             bg='#ffffff')
        self.square_area_label = tk.Label(frame, text="Area:", bg="#ffffff")
        self.square_img = Image.open(r"C:\Users\Mustafa Shah\PycharmProjects\Projects\images\dome.png")
        self.square_img.resize((400, 320))
        self.square_image = ImageTk.PhotoImage(self.square_img)
        self.square_image_label = tk.Label(frame, width=400, height=320, image=self.square_image, anchor=tk.CENTER)
        self.square_price_input_bar = tk.Entry(frame, bg='#ededed', width=10)
        self.square_price_input_bar.insert(0, str(0.00))
        self.square_calculate_button = tk.Button(frame, text="Calculate", bg="#ededed", width=20,
                                                 justify=tk.CENTER,
                                                 command=self.execute)
        self.square_feet_answer_bar = tk.Entry(frame, state=tk.DISABLED, bg='#ededed')
        self.square_inches_answer_bar = tk.Entry(frame, state=tk.DISABLED, bg='#ededed')
        self.price_answer_bar = tk.Entry(frame, state=tk.DISABLED, bg='#ededed', width=10)
        self.grid()

    def grid(self):
        self.frame_header.grid(column=0, columnspan=7, row=1, pady=5)
        for d in range(self.dimensions):
            self.side_label_list[d].grid(column=0, row=3 + d)
            self.ft_label_list[d].grid(column=2, row=3 + d)
            self.in_label_list[d].grid(column=4, row=3 + d, padx=40)
        self.square_feet_label_2.grid(column=2, row=7)
        self.square_inches_label_2.grid(column=4, row=7)
        self.square_price_per_square_foot_label_1.grid(column=1, row=5)
        self.square_price_per_square_foot_label_2.grid(column=3, row=5, pady=20)
        self.square_price_per_square_foot_label_3.grid(column=1, row=8)
        self.square_area_label.grid(column=0, row=7)
        self.square_image_label.grid(column=0, row=2, columnspan=5, padx=10, pady=5)
        for d in range(self.dimensions):
            self.ft_list[d].grid(column=1, row=3 + d, padx=20, pady=10)
            self.in_list[d].grid(column=3, row=3 + d, pady=10)
        self.square_price_input_bar.grid(column=2, row=5)
        self.square_calculate_button.grid(column=1, row=6, columnspan=3)
        self.square_feet_answer_bar.grid(column=1, row=7, pady=50)
        self.square_inches_answer_bar.grid(column=3, row=7, pady=50)
        self.price_answer_bar.grid(column=2, row=8, pady=10)

    def execute(self):
        answer_bars = []
        inches_sum_list = []
        feet_list = [int(t.get()) for t in self.ft_list]
        inches_list = [int(t.get()) for t in self.in_list]
        for b in [self.square_feet_answer_bar, self.square_inches_answer_bar, self.price_answer_bar]:
            answer_bars.append(b)
        rate = float(self.square_price_input_bar.get())
        for _ in range(self.dimensions):
            inches_sum = convert_to_inches(feet_list[_], inches_list[_])
            inches_sum_list.append(inches_sum)
        variable_dome = HalfCircle(inches_sum_list[0])
        for bar in answer_bars:
            bar.config(state=tk.NORMAL)
            bar.delete(0, tk.END)
        self.square_feet_answer_bar.insert(0, string=str(variable_dome.calculate() // 144))
        self.square_inches_answer_bar.insert(0, string=str(round(variable_dome.calculate() % 144 / 12, 2)))
        self.price_answer_bar.insert(0, string=str(round(variable_dome.calculate() / 144 * rate, 2)))
        for bar in answer_bars:
            bar.config(state=tk.DISABLED)


class Trapezoid_Display(Base):

    def __init__(self, frame):
        self.dimensions = 3
        super().__init__(frame, self.dimensions)
        self.frame_header = tk.Label(frame, text="Trapezoid Estimate", font=("Arial", 16), bg="#ffffff",
                                     justify=tk.CENTER)
        self.square_feet_label_2 = tk.Label(frame, text="FT", bg='#ffffff')
        self.square_inches_label_2 = tk.Label(frame, text="IN", bg='#ffffff')
        self.square_price_per_square_foot_label_1 = tk.Label(frame, text="Price:                    $",
                                                             bg='#ffffff')
        self.square_price_per_square_foot_label_2 = tk.Label(frame, text="per Square Foot", bg='#ffffff')
        self.square_price_per_square_foot_label_3 = tk.Label(frame, text="Total:                    $",
                                                             bg='#ffffff')
        self.square_area_label = tk.Label(frame, text="Area:", bg="#ffffff")
        self.square_img = Image.open(r"C:\Users\Mustafa Shah\PycharmProjects\Projects\images\trapezoid.png")
        self.square_img.resize((400, 320))
        self.square_image = ImageTk.PhotoImage(self.square_img)
        self.square_image_label = tk.Label(frame, width=400, height=320, image=self.square_image, anchor=tk.CENTER)
        self.square_price_input_bar = tk.Entry(frame, bg='#ededed', width=10)
        self.square_price_input_bar.insert(0, str(0.00))
        self.square_calculate_button = tk.Button(frame, text="Calculate", bg="#ededed", width=20,
                                                 justify=tk.CENTER,
                                                 command=self.execute)
        self.square_feet_answer_bar = tk.Entry(frame, state=tk.DISABLED, bg='#ededed')
        self.square_inches_answer_bar = tk.Entry(frame, state=tk.DISABLED, bg='#ededed')
        self.price_answer_bar = tk.Entry(frame, state=tk.DISABLED, bg='#ededed', width=10)
        self.grid()

    def grid(self):
        self.frame_header.grid(column=0, columnspan=7, row=1, pady=5)
        for d in range(self.dimensions):
            self.side_label_list[d].grid(column=0, row=3 + d)
            self.ft_label_list[d].grid(column=2, row=3 + d)
            self.in_label_list[d].grid(column=4, row=3 + d, padx=40)
        self.square_feet_label_2.grid(column=2, row=8)
        self.square_inches_label_2.grid(column=4, row=8)
        self.square_price_per_square_foot_label_1.grid(column=1, row=6)
        self.square_price_per_square_foot_label_2.grid(column=3, row=6, pady=20)
        self.square_price_per_square_foot_label_3.grid(column=1, row=9)
        self.square_area_label.grid(column=0, row=8)
        self.square_image_label.grid(column=0, row=2, columnspan=5, padx=10, pady=5)
        for d in range(self.dimensions):
            self.ft_list[d].grid(column=1, row=3 + d, padx=20, pady=10)
            self.in_list[d].grid(column=3, row=3 + d, pady=10)
        self.square_price_input_bar.grid(column=2, row=6)
        self.square_calculate_button.grid(column=1, row=7, columnspan=3)
        self.square_feet_answer_bar.grid(column=1, row=8, pady=50)
        self.square_inches_answer_bar.grid(column=3, row=8, pady=50)
        self.price_answer_bar.grid(column=2, row=9, pady=10)

    def execute(self):
        answer_bars = []
        inches_sum_list = []
        feet_list = [int(t.get()) for t in self.ft_list]
        inches_list = [int(t.get()) for t in self.in_list]
        for b in [self.square_feet_answer_bar, self.square_inches_answer_bar, self.price_answer_bar]:
            answer_bars.append(b)
        rate = float(self.square_price_input_bar.get())
        for _ in range(self.dimensions):
            inches_sum = convert_to_inches(feet_list[_], inches_list[_])
            inches_sum_list.append(inches_sum)
        variable_trapezoid = Trapezoid(inches_sum_list[0], inches_sum_list[1], inches_sum_list[2])
        for bar in answer_bars:
            bar.config(state=tk.NORMAL)
            bar.delete(0, tk.END)
        self.square_feet_answer_bar.insert(0, string=str(variable_trapezoid.calculate() // 144))
        self.square_inches_answer_bar.insert(0, string=str(round(variable_trapezoid.calculate() % 144 / 12, 2)))
        self.price_answer_bar.insert(0, string=str(round(variable_trapezoid.calculate() / 144 * rate, 2)))
        for bar in answer_bars:
            bar.config(state=tk.DISABLED)


class L_Shape_Display(Base):

    def __init__(self, frame):
        self.dimensions = 4
        super().__init__(frame, self.dimensions)
        self.frame_header = tk.Label(frame, text="L Shape Estimate", font=("Arial", 16), bg="#ffffff",
                                     justify=tk.CENTER)
        self.square_feet_label_2 = tk.Label(frame, text="FT", bg='#ffffff')
        self.square_inches_label_2 = tk.Label(frame, text="IN", bg='#ffffff')
        self.square_price_per_square_foot_label_1 = tk.Label(frame, text="Price:                    $",
                                                             bg='#ffffff')
        self.square_price_per_square_foot_label_2 = tk.Label(frame, text="per Square Foot", bg='#ffffff')
        self.square_price_per_square_foot_label_3 = tk.Label(frame, text="Total:                    $",
                                                             bg='#ffffff')
        self.square_area_label = tk.Label(frame, text="Area:", bg="#ffffff")
        self.square_img = Image.open(r"C:\Users\Mustafa Shah\PycharmProjects\Projects\images\l_shape.png")
        self.square_img.resize((400, 320))
        self.square_image = ImageTk.PhotoImage(self.square_img)
        self.square_image_label = tk.Label(frame, width=400, height=320, image=self.square_image, anchor=tk.CENTER)
        self.square_price_input_bar = tk.Entry(frame, bg='#ededed', width=10)
        self.square_price_input_bar.insert(0, str(0.00))
        self.square_calculate_button = tk.Button(frame, text="Calculate", bg="#ededed", width=20,
                                                 justify=tk.CENTER,
                                                 command=self.execute)
        self.square_feet_answer_bar = tk.Entry(frame, state=tk.DISABLED, bg='#ededed')
        self.square_inches_answer_bar = tk.Entry(frame, state=tk.DISABLED, bg='#ededed')
        self.price_answer_bar = tk.Entry(frame, state=tk.DISABLED, bg='#ededed', width=10)
        self.grid()

    def grid(self):
        self.frame_header.grid(column=0, columnspan=7, row=1, pady=5)
        for d in range(self.dimensions):
            self.side_label_list[d].grid(column=0, row=3 + d)
            self.ft_label_list[d].grid(column=2, row=3 + d)
            self.in_label_list[d].grid(column=4, row=3 + d, padx=40)
        self.square_feet_label_2.grid(column=2, row=9)
        self.square_inches_label_2.grid(column=4, row=9)
        self.square_price_per_square_foot_label_1.grid(column=1, row=7)
        self.square_price_per_square_foot_label_2.grid(column=3, row=7, pady=20)
        self.square_price_per_square_foot_label_3.grid(column=1, row=10)
        self.square_area_label.grid(column=0, row=9)
        self.square_image_label.grid(column=0, row=2, columnspan=5, padx=10, pady=5)
        for d in range(self.dimensions):
            self.ft_list[d].grid(column=1, row=3 + d, padx=20, pady=10)
            self.in_list[d].grid(column=3, row=3 + d, pady=10)
        self.square_price_input_bar.grid(column=2, row=7)
        self.square_calculate_button.grid(column=1, row=8, columnspan=3)
        self.square_feet_answer_bar.grid(column=1, row=9, pady=50)
        self.square_inches_answer_bar.grid(column=3, row=9, pady=50)
        self.price_answer_bar.grid(column=2, row=10, pady=10)

    def execute(self):
        answer_bars = []
        inches_sum_list = []
        feet_list = [int(t.get()) for t in self.ft_list]
        inches_list = [int(t.get()) for t in self.in_list]
        for b in [self.square_feet_answer_bar, self.square_inches_answer_bar, self.price_answer_bar]:
            answer_bars.append(b)
        rate = float(self.square_price_input_bar.get())
        for _ in range(self.dimensions):
            inches_sum = convert_to_inches(feet_list[_], inches_list[_])
            inches_sum_list.append(inches_sum)
        variable_l_shape = L_Shape(inches_sum_list[0], inches_sum_list[1], inches_sum_list[2], inches_sum_list[3])
        for bar in answer_bars:
            bar.config(state=tk.NORMAL)
            bar.delete(0, tk.END)
        self.square_feet_answer_bar.insert(0, string=str(variable_l_shape.calculate() // 144))
        self.square_inches_answer_bar.insert(0, string=str(round(variable_l_shape.calculate() % 144 / 12, 2)))
        self.price_answer_bar.insert(0, string=str(round(variable_l_shape.calculate() / 144 * rate, 2)))
        for bar in answer_bars:
            bar.config(state=tk.DISABLED)


# Miscellaneous Commands
def convert_to_inches(feet: int = 0, inches: int = 0):
    return (feet * 12) + inches
