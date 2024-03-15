import shelve

class NOTES:
    def __init__(self):
        self.notes = [[False, 0, "5.0"]]
        try:
            with shelve.open("noteData") as storage:
                file = storage.get("notes", [])
        except:
            file = []  # Creating a variable to avoid errors

        if file and len(file) > 0:  # Check if file has elements
            if file[0][0] is True:
                length = len(file) - 1
                self.notes.extend(file[1:])  # Extend notes with contents of file[1:]
                self.notes[0][0] = True
                self.notes[0][1] += length


    def save(self):
        try:
            with shelve.open("noteData") as storage:
                storage["notes"] = self.notes
            return True
        except:
            return False
    
    def is_empty(self, variable):
        return not variable or variable.strip() == ""
    
    def insert(self,heading, notes):
        has_heading = not self.is_empty(heading)
        note_cache = []
        note_cache.append(has_heading)
        note_cache.append(heading)
        note_cache.append(notes)
        
        self.notes.append(note_cache)    # note_cache is set, adding new information to notes
        self.notes[0][0] = True
        self.notes[0][1] += 1


    def delete(self, index):
        if 0 < index <= self.notes[0][1]: 
            self.notes.pop(index)
            self.notes[0][1] -= 1
            if self.notes[0][1] == 0:
                self.notes[0][0] = False
    

    def access(self, index):
        if 0 < index <= self.notes[0][1]:
            return [self.notes[index][1], self.notes[index][2]]
        else:
            return ["", ""]

    
    def available(self,index):
        if 0 < index <= self.notes[0][1]:
            return True
        else:
            return False


    def veiw(self, index):
        string_cache = ""
        if not self.is_empty(self.notes[index][1]):
            string_cache = string_cache + self.notes[index][1] + "\n"
        if not self.is_empty(self.notes[index][2]):
            string_cache = string_cache + self.notes[index][2]
        return string_cache


import tkinter as tk
from tkinter import simpledialog


dark =  ["#212121", "#181818", "#f0f0f0", "Dark Theme 🌙", 1]
light = ["#f0f0f0", "#bfbfbf","#212121", "Light Theme 🔆", 0]
theme = dark

Notes = NOTES()

class TKTOOLS():
    def __init__(self):
        self.frames = []
        self.labels = []
        self.buttons = []
        self.canvas_buttons = []


    def ThemeButton(self):
        global theme
        if theme[4]== 1:
            theme = light
        else:
            theme = dark
        self.buttons[0].configure(bg=theme[0], fg=theme[2], text=theme[3])
        self.buttons[1].configure(bg=theme[0], fg=theme[2])
        self.buttons[2].configure(bg=theme[0], fg=theme[2])
        for button in self.canvas_buttons:
            button.configure(bg=theme[0], fg=theme[2])
        for frame in self.frames:
            frame.configure(bg=theme[1])
        self.labels[0].configure(bg=theme[1], fg=theme[2])
        self.canvas.configure(bg=theme[0])
        window.configure(bg=theme[0])
        

    def editor_window(self, string1, string2, index= -2):
        def save():
            edited_strings = [entry1.get(), entry2.get()]
            if index != -2:
                Notes.delete(index)
            Notes.insert(edited_strings[0], edited_strings[1])
            Notes.save()
            editorWindow.destroy()

        editorWindow = tk.Toplevel()  # Use Toplevel instead of Tk
        editorWindow.title("Edit Window")

        label1 = tk.Label(editorWindow, text="String 1:")
        label1.grid(row=0, column=0, padx=5, pady=5)
        entry1 = tk.Entry(editorWindow, width=100)
        entry1.grid(row=0, column=1, padx=5, pady=5)
        entry1.insert(tk.END, string1)

        label2 = tk.Label(editorWindow, text="String 2:")
        label2.grid(row=1, column=0, padx=5, pady=5)
        entry2 = tk.Entry(editorWindow, width=100)
        entry2.grid(row=1, column=1, padx=5, pady=5)
        entry2.insert(tk.END, string2)

        save_button = tk.Button(editorWindow, text="Save", command=save)
        save_button.grid(row=2, columnspan=2, padx=5, pady=5)


    def canvas_button_command(self, index):
        value = Notes.access(index)
        self.editor_window(value[0], value[1], index)


    def frame1(self):
        # Create frame at the top
        self.frames.append(tk.Frame(window, bg=theme[1], relief=tk.FLAT))
        self.frames[0].pack(side=tk.TOP, fill=tk.X)

        # Create label in the top frame
        self.labels.append(tk.Label(self.frames[0], text="📝 Keep Notes", bg=theme[1], fg=theme[2], font=("Arial", 12, "bold")))
        self.labels[0].pack(side=tk.LEFT, padx=5, pady=5)

        self.buttons.append(tk.Button(self.frames[0], text=theme[3], bg=theme[0], fg= theme[2], command=self.ThemeButton))
        self.buttons[0].pack(side=tk.RIGHT, padx=5)

        self.buttons.append(tk.Button(self.frames[0], text="Refresh🔁", bg=theme[0], fg= theme[2], command=self.refresh_canvas_buttons))
        self.buttons[1].pack(side=tk.RIGHT, padx=5)
        

    def create_note_command(self):
        self.editor_window("Type a heading", "Type your notes")


    def frame2(self):
        # Create frame at the bottom
        self.frames.append(tk.Frame(window, bg=theme[1], relief=tk.FLAT))
        self.frames[1].pack(side=tk.BOTTOM, fill=tk.X)

        self.buttons.append(tk.Button(self.frames[1], text=f"Create Note", command= self.create_note_command, bg=theme[0], fg=theme[2]))
        self.buttons[2].pack(side=tk.LEFT, fill=tk.X, expand=True, padx=5)


    def on_canvas_configure(self, event):
        self.canvas.configure(scrollregion=self.canvas.bbox("all"))


    def refresh_canvas_buttons(self):
        for button in self.canvas_buttons:
            button.destroy()

        Width = 122
        j = 1
        while Notes.available(j):
            command = lambda index=j: self.canvas_button_command(index)
            button = tk.Button(self.frames[3], command=command, text=Notes.veiw(j), bg=theme[0], fg=theme[2], width=Width, anchor="w")
            button.pack(fill=tk.X, padx=5, pady=5)
            self.canvas_buttons.append(button)
            j += 1


    def frame3(self):
        self.frames.append(tk.Frame(window, bg=theme[0])) # Create frame to hold canvas and scrollbar
        self.frames[2].pack(fill=tk.BOTH, expand=True)

        self.canvas = tk.Canvas(self.frames[2], bg=theme[0]) # Create canvas for scrollable area
        self.canvas.pack(side=tk.LEFT, fill=tk.BOTH, expand=True)

        self.scrollbar = tk.Scrollbar(self.frames[2], orient=tk.VERTICAL, command=self.canvas.yview) # Create scrollbar for canvas
        self.scrollbar.pack(side=tk.RIGHT, fill=tk.Y)
        self.canvas.configure(yscrollcommand=self.scrollbar.set)

        self.frames.append(tk.Frame(self.canvas, bg=theme[0])) # Create frame inside canvas to hold content
        self.canvas.create_window((0, 0), window=self.frames[3], anchor=tk.NW)

        # Add buttons to the frame
        self.refresh_canvas_buttons()
        # Update canvas scrolling region
        self.canvas.bind("<Configure>", self.on_canvas_configure)


tkTools = TKTOOLS()
window = tk.Tk()

window.title("📝 Keep Notes")
window.geometry("900x570")
window.configure(bg=theme[0])

tkTools.frame1()
tkTools.frame2()
tkTools.frame3()

window.mainloop()