# Spacemacs Rocks
## Day 1:
1. `M-x linum-mode`: shows line numbers
2. Help from Emacs
   - `C-h k`: help for keys, e.g. `C-h k C-x C-s`
   - `C-h v`: help for variables
   - `C-h f`: help for functions
3. When edit dot emacs file, tying ";" returns incorrect indent. Doing `M-x electric-indent-mode` to close the mode.
4. `C-x C-f ~/.emacs.d/init.el`: edits the init file
5. `C-h m`: shows all minor modes
6. Org mode
   - `C-c C-t`: adds a TODO states
### Key Binding
1. `F1`: opens the init file
### Reference: [Spacemacs Rock Day 1](https://www.youtube.com/watch?v=QKhS9EX9qd8&list=PLqQgufb9_uJeSg3ChhgcDHD9C5MbZSCal&index=18)

## Day 2:
1. Org mode
   - With in `#+BEGIN_SRC emacs-lisp` to `#+END_SRC`, `C-c '` to open a new buffer and get back to the original file.
   - `<s tab`: adds "#+BEGIN_SRC" and "#+END_SRC"
   - `C-c C-s`: schedule an event
   - `C-c C-d`: set a deadline for an event
   - `M-RET`: auto correct built point numbers
2. `M-x eval-buffer`: execute the whole buffer
3. `M-x package-list-packages`: opens the package list
   - `i`: install
   - `u`: undo `i`
   - `C-s`: search a package
   - `d`: uninstall
   - `U`: updates all packages
   - `x`: executes
4. `M-x package-autoremove`: removes unnecessary packages
5. `M-x customize-group`: customize packages
6. `M-return`: automatically correct list number
### Key Binding
1. `C-x C-r`: opens recent files
2. `C-s` after `M-x <command>`: switches to the next option
### Reference: [Spacemacs Rock Day 2](https://www.youtube.com/watch?v=l6TzOIlS8Ec&list=PLqQgufb9_uJeSg3ChhgcDHD9C5MbZSCal&index=4)

## Day 3:
### Reference: [Spacemacs Rock Day 3](https://www.youtube.com/watch?v=hL9B2AtcB1w&list=PLqQgufb9_uJeSg3ChhgcDHD9C5MbZSCal&index=5)

## Day 4:
1. `s-/`: (left command) hipple-expand (another way of completion)
2. Dired mode
   - `C-x d`: runs dired
   - `+`: creates directory
   - `C-x C-f`: creates a file
   - `g`: refreshs dired buffer
   - `C`: copies a file
   - `d`: deletes a file
   - `D`: deletes a file after confirmation
   - `R`: renames a file
   - `x`: execute
   - `C-x C-j`: opens current folder
### Reference: [Spacemacs Rock Day 4](https://www.youtube.com/watch?v=IhCOO0R83G8&list=PLqQgufb9_uJeSg3ChhgcDHD9C5MbZSCal&index=3)

## Day 5:
1. Occur mode
   - `C-c o`: finds out when words occur
   - After finding all words, `e` to enter the Occur-Edit mode
   - After editing, `C-c C-c` to exit the Occur-Edit mode
2. counsel-imenu
   - `C-c i`: searchs function names
3. expand-region
   - `C-=`: selects region
   - `+`: expand 
   - `-`: contract (`+` only, no `C` with it)
   - `0`: reset
4. iedit mode
   - `C-;`: starts iedit
### Reference: [Spacemacs Rock Day 5](https://www.youtube.com/watch?v=Tjh5cKAw1Ks&list=PLqQgufb9_uJeSg3ChhgcDHD9C5MbZSCal&index=6)

## Day 6:
1. Org mode
   - `C-c C-s`: schedule an event
   - `C-c C-d`: deadline of an event
   - `C-c a a`: opens the agenda
   - `r`: refresh
   - `d`: the daily agenda
   - `w`: the week agenda
   - `C-c r`: creates a TODO by using TODO template
2. Org-pomodoro mode
   - `C-a a`: starts the agenda
   - `n` or `p`: to the target task
   - `M-x org-pomodoro`: starts org-pomodoro
3. Dired mode
   - `Shift-6`: returns to the parent folder
   - `g`: refreshs dired buffer
   - `C-x C-q`, then `C-=` to select the title, then `C-;` to modify more than one file's name
4. Helm-ag
   - Install ag
   - `C-c p s`: searchs by using ag
   - `!`: do not include (similar with gitignore)
   - After searching, `C-c C-e` starts edit in different files
5. flycheck and eslint
   - `npm install -g eslint`: install eslint
   - `C-c ! l`: shows the list of errors
6. auto yasnippets
   - Would like to type as following
   ```
   (add-to-listAA 'pathAA 'xxxAA)
   (add-to-listBB 'pathBB 'xxxBB)
   (add-to-listCC 'pathCC 'xxxCC)
   ```
   - (add-to-list~AA 'path~AA 'xxx~AA)
   - `C-c w`: creates auto-yasnippet template, "~" will be removed automaticlly
   - `C-c e`: pastes the template
   - Then, type "BB"
   - `C-c e`, then type "CC"

## Day 7:
1. `C-w`: deletes a word
2. `C-z`: switches between emacs and vim modes (vim has to be in the NORMAL mode)
3. vim mode
   - `C-w h`: switches to the left window
   - `C-w l`: switches to the right window
   - 'hello', change it to "hello": within hello, `cs'"` (Shift+9, includes spaces; Shift+0, NOT includes spaces)
