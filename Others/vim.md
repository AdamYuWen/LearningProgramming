# Vim Notes

1. `H`: head of the page
   `M`: middle of the page
   `L`: bottom (low) of the page
2. `b`: beginning of the word
   `e`: end of the word
3. Change multiple same words
   `*`: select current word (go back with `N`)
   `gn`: change word with `gn` motion. e.g. `cgnfoo<esc>`
   `.`: repeat
4. Copy a word, then change another word with the copied one
   `yiw`: copy of the word
   `viwp`: select of the word and paste the copied one
5. `%`: on a bracket and to the matching bracket
6. `{`: to the beginning of the block
7. `}`: to the end of the block
8. `D`: delete from the cursor to the end of the line
9. `C`: delete from the cursor to the end of the line and change
10. `t`: go to somewhere in the line. For example, `t!` goes to the character before !
11. `f`: find the character. For example, `f!` find ! and move the cursor on it
12. `dt`: delete from the cursor to something. For example, `dt!`
13. `*`: move cursor to the same word
14. `;`: goes to the next instance of a character. For example, `fm` finds the character m and `;` finds the next m
15. `zz`: center the cursor
16. `~`: swap the character from capital to lower case or lower case to capital
17. `.`: redo the last command
18. `0w`: to the first non-empty character
19. macro
    1. `q`: start a macro
    2. any key: save the macro to a key
    3. command: record a macro
    4. `q`: end a macro
    5. `@<key>`: replay the macro
20. `/<something>+enter`: search for something, then `n` to the next
21. macro to change a word at multiple places
    1. `q`: start a macro
    2. any key: save the macro to a key
    3. command: change + `/<something>`
    4. `q`: end a macro
22. `u`: undo
23. `ctrl+r`: redo
