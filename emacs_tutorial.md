### Emacs Tutorial (`C-h, t`)
#### Summary
1. `C-v`: Move forward one screenful
   `M-v`: Move backward one screenful
   `C-l`: Move the text around the cursor
#### Basic Cursor Control
1. `C-p`, `C-n`, `C-b`, `C-f`, `M-b`, `M-f`, `C-a`, `C-e`, `M-a`, `M-e`
   - `M-b`, `M-f`: Move by words
   - `M-a`, `M-e`: Move by sentences
2. Repeat-count
   - `C-u 8 C-f`: Moves forward eight characters
   - `C-u 3 C-n`: Moves down three lines
#### Inserting and Deleting
1. If you do serval `C-k`'s in a row, all of the killed text is saved together, so that one `C-y` will yank all of the lines at onces.
2. __Yanking previous kills__: After you have done `C-y` to get the most recent kill, typing `M-y`replaces that yanked text with the previous kill. Typing `M-y` again and again brings in earlier and earlier kills.
#### Buffers
1. `C-x b`: Easier way to switch between buffers
#### Auto Save
1. _#hello.c#_: It's an example of a auto save file
2. To find the auto-saved file, `M-x recover-file <Return>`
#### Mutiple Windows
1. `C-M-v`: Scroll the next window, without going into the window
#### Mutiple Frame
1. `M-x make-frame <Return>`: Create a new frame (window)
2. `M-x delete-frame <Return>`: Delete the frame
#### Getting More Help
1. `C-h ?`: Get for any help
2. `C-h c`: Get help for a command, e.g. `C-h c C-p`
3. `C-h k`: Get for information about command, e.g. `C-h k C-p`
4. `C-h f`: Get help for a function
5. `C-h v`: Get help for a variable