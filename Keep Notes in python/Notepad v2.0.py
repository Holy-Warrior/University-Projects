# structure of nested notes :
#     notes = [[has_notes, amount_notes, version],[has_heading, heading, note],[has_heading, heading, note]]
#     the first nested list defines the condition of the entire notes, others are independent note data

notes = [[False, 0, "2.0"]]
# The following is a sample file import
# file = [[True, 2, "sample"], [True, "Introduction", "Hello world, this is a test note"], [False, "", "Sup guys! \nnothing to see here"]]


import tkinter as tk
from tkinter import simpledialog
def tk_gui(note_title = "Edit your note:",set_note = "Type Here"):    # A simple function for the note_editor() function
    root = tk.Tk()  # Create a Tkinter window
    # root.title("Edit Note")

    note_variable = tk.StringVar() # Sample note variable
    note_variable.set(set_note)

    # Create a text input field (writing box)
    text_input = simpledialog.askstring("Edit Note", note_title, initialvalue=note_variable.get())
    root.destroy() # Close the window
    return text_input


import shelve
def save_file(data = notes):
    try:
        with shelve.open("noteData") as storage:
            storage["notes"] = data
        print("Data saved successfully.")
        return True
    except Exception as e:
        print(f"Error occurred while saving data: {str(e)} 😔")
        return False


def load_file():
    try:
        with shelve.open("noteData") as storage:
            file = storage.get("notes", [])
    except Exception as e:
        print(f"Error occurred while reading data: {str(e)} 😔")
        file = []

    if file and len(file) > 0:  # Check if file has elements
        if file[0][0] is True:
            length = len(file) - 1
            notes.extend(file[1:])  # Extend notes with contents of file[1:]
            notes[0][0] = True
            notes[0][1] += length
            return [True, length]
    return [False, 0]


def is_empty(user_input):
    return not user_input or user_input.strip() == "" # strip() function removes white spaces in " " and "hi "


def total_bool_input(message = None):
    if message == None:
        string_input = input()
    else:
        string_input = input(message)
    if string_input == "0" or string_input == "False" or string_input == "FALSE" or string_input == "false" or string_input == "No" or string_input == "NO" or string_input == "no" or string_input =="n" or string_input == "N" or string_input == "f" or string_input == "F":
        return False
    elif string_input == "1" or string_input == "True" or string_input == "TRUE" or string_input == "true" or string_input == "Yes" or string_input == "YES" or string_input == "yes" or string_input =="y" or string_input == "Y" or string_input == "t" or string_input == "T":
        return True
    else:
        print("A pretty dumb person you are to bypass all my error handeling and managed to come here")
        return "hahaha take that, crash with an error. seriously this will only display true in a conditional function"


def insert_note():
    note_cache = []
    user_input = None
    user_input = input("Write a note:\n")
    if is_empty(user_input):
        print("Empty note discarded")
    else:
        note_cache.append(user_input)
        user_input = None
        user_input = input("Add heading(optional, hit ENTER to skip):\n")
        if is_empty(user_input):
            note_cache.insert(0, False)
            note_cache.insert(1, "")
        else:
            note_cache.insert(0, True)
            note_cache.insert(1, user_input)
        
        notes.append(note_cache)    # note_cache is set, adding new information to notes
        notes[0][0] = True
        notes[0][1] += 1
        print("Note created!")


def note_editor(note_index):
    print(f"Editing note {note_index}")
    note_cache = notes[note_index]
    note_cache[2] = tk_gui("Edit your note:", note_cache[2])
    if note_cache[0] == False:
        print("Add a heading?")
        add_heading = total_bool_input()
        if add_heading:
            note_cache[1] = tk_gui("Add a heading:", "Type here")
            if note_cache[1] is not None:
                note_cache[0] = True
            else:
                note_cache[1] = ""
    else:
        print("Edit heading?")
        edit_heading = total_bool_input()
        if edit_heading:
            note_cache[1] = tk_gui("Edit your heading:", note_cache[1])
            if note_cache[1] is not None:
                note_cache[0] = True
            else:
                note_cache[1] = ""
                note_cache[0] = False
    print(f"\nNote-{note_index}:")
    if note_cache[0] == True:
        print(note_cache[1])
    print(note_cache[2])
    save_this_note = total_bool_input("Confirm to save this note?: ")
    if save_this_note:
        notes.pop(note_index)
        notes.insert(note_index, note_cache)
    else:
        print("Note discarded")


def access_note():
    while True:
        display_notes()
        notes_length = len(notes) -1
        choice = int(input(f"Choose your option from 1 to {notes_length}: "))
        if choice > notes_length or choice < 1:
            print(f"Invalid argument error! No note found with index {choice}")
        else:
            print(f"\nNote-{choice}:")
            if notes[choice][0] == True:
                print(notes[choice][1])
            print(notes[choice][2])
        
            print("\nOptions:\n  1.Edit this note\n  2.Delete this note\n  3.Back to main window")
            choice2 = int(input("Your choice: "))
            if choice2 == 1:
                note_editor(choice)
            elif choice2 == 2:
                delete_note(choice)
                break
            elif choice2 == 3:
                print("Going back to main window")
                break
            else:
                print("Invalid argument error! Choose available option [1/2/3]")



def delete_note(delete_from_index = 0): ## take 0 value for full delete menu, and greater than above for direct delete
    if delete_from_index == 0:
        display_notes()
        notes_length = len(notes) -1
        choice = int(input(f"Choose your option from 1 to {notes_length}: "))
        if choice > notes_length or choice < 1:
            print(f"Invalid argument error! No note found with index {choice}")
        else:
            print(f"\nNote-{choice}:")
            if notes[choice][0] == True:
                print(notes[choice][1])
            print(notes[choice][2])

            print("Confirmation: Delete this note? [0/1]")
            confirmation = total_bool_input()
            if confirmation == True:
                notes.pop(choice)
                print(f"Note-{choice} deleted")

    elif delete_from_index > 0:
        print("Confirmation: Delete this note? [0/1]")
        confirmation = total_bool_input()
        if confirmation == True:
            notes.pop(delete_from_index)
            print(f"Note-{delete_from_index} deleted")


def load_program():
    notes_loaded_from_file = load_file()
    if notes_loaded_from_file[0]:
        print(f"File loaded with {notes_loaded_from_file[1]} notes")
    else:
        print("No files found...")


def display_notes():
    skip = True
    counter = -1

    print("-------------------------------")
    for note in notes:
        counter += 1
        if skip is True:                  # skipping index 0 which stores details of all notes
            print("Your Notes:")          # instead the window shows the start of menu
            skip = False
        else:
            print(f"\nNote-{counter}:")     # Note-1
            if len(note) >= 3:            # Check if note has at least 3 elements
                if note[0] is True:       # Heading (if true)
                    print(note[1])
                else:
                    note_content = note[2]                    # Display first 10 characters of the note content
                    displayed_content = note_content[:10]     # Check if the word was incomplete at character 10
                    if len(note_content) > 10 and note_content[10] != " ":   # Find the next space after the 10th character
                        next_space_index = note_content.find(" ", 10)
                        if next_space_index != -1:                           # Display characters until the next space
                            displayed_content += note_content[10:next_space_index]
                        else:                                                # If no space is found, display the characters until the end
                            displayed_content += note_content[10:]
                    print(displayed_content + " ...")
            else:
                print("Incomplete note\n")    # Handle incomplete notes
    print("-------------------------------")


def menu():
    notes_available = False
    notes_available = notes[0][0]
    if notes[0][0] is False:
        notes_available = True
        print("Message: No notes to be seen")
    else:
        display_notes()
    while True:
        print("Choose your option")
        print("  1.Insert a note")
        if notes_available:
            print("  2.Access a note")
            print("  3.Delete a note")
        else:
            print("  2.Access a note[Feature unavailable]")
            print("  3.Delete a note[Feature unavailable]")
        print("  4.End program")

        choice = input("Your choice: ")
        if choice == "1":
            insert_note()
        elif choice == "2":
            if notes_available:
                access_note()
            else:
                print("There are no notes to access")
        elif choice == "3":
            if notes_available:
                delete_note()
            else:
                print("There are no notes to access")
        elif choice == "4":
            print("Closing the program...")
            save_file()
            print("Program safely closed")
            break
        else:
            print("Invalid argument error! choose from [1/2/3/4]")


################################# { Program } #################################

load_program() # loads file and appends it to notes
menu() # displays available notes list and options to work on
