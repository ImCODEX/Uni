import tkinter as tk
class NewWindow:
    def __init__(self, root, controller):
        self.root = root
        self.root.title('My Second Window')
        self.root.geometry('1500x400')
        self.controller = controller

        self.top = tk.Frame(self.root)

        self.button_quit = tk.Button(self.top,  text='Quit', command=self.close)
        self.button_quit.pack(fill=tk.BOTH)

        self.text = tk.Text(self.top)


        l = self.controller.show_guests()
        l = "\n".join(l)
        Lb1 = tk.Listbox(self.root, width= 400)
        Lb1.insert(1, l)
        Lb1.pack()

        self.text.pack(fill=tk.BOTH)
        self.top.pack()
    def close(self):
        self.root.destroy()

    def save(self):
        with open('text.txt', 'w') as f:
            f.write(self.text.get('1.0', tk.END))