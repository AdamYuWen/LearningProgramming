# Spacemacs Rocks
## Day 1:
1. `M-x linum-mode`: shows line numbers
2. Help from Emacs
   - `C-h k`: help for keys, e.g. `C-h k C-x C-s`
   - `C-h v`: help for variables
   - `C-h f`: help for functions
3. When edit dot emacs file, tying ";" returns incorrect indent. Doing `M-x electric-indent-mode` to close the mode.
4. `C-x C-f ~/.emacs.d/init.el`: edits the init file
5. `M-x package-list-packages`: opens the package list
6. `C-h m`: shows all minor modes
7. Org mode
   - `C-c C-t`: adds a TODO states
```
;; Remove the incorrect indent in .emacs
(electric-indent-mode -1)
;; Remove the tool bar
(tool-bar-mode -1)
;; Remove the scroll bar
(scroll-bar-mode -1)
;; Unshow the welcome page
(setq inhibit-splash-screen t)
;; Set the line number
(global-linum-mode t)
;; Set cursor to a bar
(setq-default cursor-type 'bar)

;; Set F1 to open the init.el file
(defun open-my-init-file()
  (interactive)
  (find-file "~/.emacs.d/init.el"))
(global-set-key (kbd "<f1>") 'open-my-init-file)

;; Set the company mode
(global-company-mode t)
```
### Reference: [Spacemacs Rock Day 1](https://www.youtube.com/watch?v=QKhS9EX9qd8&list=PLqQgufb9_uJeSg3ChhgcDHD9C5MbZSCal&index=18)
