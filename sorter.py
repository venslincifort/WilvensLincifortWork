import os
import shutil
import tkinter as tk
from tkinter import filedialog, messagebox

# Dictionary for file categories
FILE_TYPES = {
    "Images": [".jpg", ".jpeg", ".png", ".gif", ".bmp"],
    "Documents": [".pdf", ".docx", ".doc", ".txt", ".rtf", ".odt", ".xlsx", ".csv", ".pptx"],
    "Audio": [".mp3", ".wav", ".aac", ".flac"],
    "Video": [".mp4", ".mov", ".avi", ".mkv"],
    "Code": [".py", ".java", ".cpp", ".c", ".js", ".html", ".css", ".sql"],
    "Compressed": [".zip", ".rar", ".tar", ".gz", ".7z"],
    "Executables": [".exe", ".msi", ".sh", ".bat"],
    "Others": []  # For uncategorized files
}

def file_sorter(source_folder):
    # Create folders if they don’t exist
    for folder in FILE_TYPES.keys():
        folder_path = os.path.join(source_folder, folder)
        os.makedirs(folder_path, exist_ok=True)

    # Sort files
    for filename in os.listdir(source_folder):
        file_path = os.path.join(source_folder, filename)

        if os.path.isfile(file_path):  # Only process files
            moved = False
            for folder, extensions in FILE_TYPES.items():
                if any(filename.lower().endswith(ext) for ext in extensions):
                    shutil.move(file_path, os.path.join(source_folder, folder, filename))
                    moved = True
                    break

            # If no match, move to "Others"
            if not moved:
                shutil.move(file_path, os.path.join(source_folder, "Others", filename))

def browse_folder():
    folder_selected = filedialog.askdirectory()
    if folder_selected:
        folder_path.set(folder_selected)

def sort_files():
    path = folder_path.get()
    if not path:
        messagebox.showerror("Error", "Please select a folder first.")
        return

    try:
        file_sorter(path)
        messagebox.showinfo("Success", "Files sorted successfully!")
    except Exception as e:
        messagebox.showerror("Error", f"An error occurred:\n{e}")

# GUI setup
root = tk.Tk()
root.title("File Sorter")
root.geometry("400x200")

folder_path = tk.StringVar()

label = tk.Label(root, text="Select a folder to sort:", font=("Arial", 12))
label.pack(pady=10)

entry = tk.Entry(root, textvariable=folder_path, width=40)
entry.pack(pady=5)

browse_btn = tk.Button(root, text="Browse", command=browse_folder)
browse_btn.pack(pady=5)

sort_btn = tk.Button(root, text="Sort Files", command=sort_files, bg="green", fg="white")
sort_btn.pack(pady=15)

root.mainloop()
