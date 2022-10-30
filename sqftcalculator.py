from shapestorage import *

root = tk.Tk()
root.title("Square Footage Estimator")
screen_width = root.winfo_screenwidth()
screen_height = root.winfo_screenheight()
x_coordinate = int((1500/2) - (525/2))
y_coordinate = int((1000/2) - (850/2) - 40)
root.geometry("{}x{}+{}+{}".format(525, 850, x_coordinate, y_coordinate))
root.iconbitmap(r'C:\Users\Mustafa Shah\PycharmProjects\Projects\images\Iconsmind-Outline-Pencil-Ruler.ico')

# Permanent GUI Widgets
header = tk.Label(root, text="Square Footage Estimator", font=("Arial", 18), justify=tk.CENTER)
header.grid(column=0, row=0, columnspan=5, pady=10)
shape_select = tk.Menu(root)
shape_select.add_command(label="Square", command=lambda: Square_Display(frame))
shape_select.add_command(label="Rectangle", command=lambda: Rectangle_Display(frame))
shape_select.add_command(label="Triangle", command=lambda: Triangle_Display(frame))
shape_select.add_command(label="Circle", command=lambda: Circle_Display(frame))
shape_select.add_command(label="Dome", command=lambda: Dome_Display(frame))
shape_select.add_command(label="Trapezoid", command=lambda: Trapezoid_Display(frame))
shape_select.add_command(label="L Shape", command=lambda: L_Shape_Display(frame))
root.config(menu=shape_select)
frame = tk.LabelFrame(root, width=300, height=400, bg='#ffffff')
frame.grid(columnspan=5, column=0, row=1, rowspan=6, padx=20)

# Initializer
Square_Display(frame)

root.resizable(width=False, height=False)
root.mainloop()
