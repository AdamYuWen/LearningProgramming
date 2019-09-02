# Class 2-1
1. Convert NORMAL mode to INSERT mode (a, i, o)
   - `a`: append
   - `i`: insert
   - `o`: open a new line below
   - `A`: append at the end of the line
   - `I`: insert at the beginning of the line
   - `O`: open a new line above
2. Convert INSERT mode to NORMAL mode (ESC)
3. `:q`: quit
4. `:wq`: written and quit
5. `:e!`: edits but discard any changes to the current buffer

# Class 2-2
## COMMAND mode
1. `:vs`: vertial split
2. `:sp`: split
3. `:% s/foo/bar/g`: change all "foo" to "bar" in the file
4. `:set nu`: set line numbers
5. `/word`: search "word" in the file
## VISUAL mode
1. `v`: select start
2. `V`: select the whole line
3. `ctrl+v`: select a block

# Class 2-3
## INSERT mode
1. `ctrl+h`: delete last character
2. `ctrl+w`: delete last word
3. `ctrl+u`: delete current line
4. Set up `ctrl+c` or `ctrl+[` to convert from INSERT to NORMAL
## NORMAL mode
1. `gi`: go to the last edit place and insert

# Class 2-4
## NORMAL mode
1. `h`, `j`, `k`, `l`: left, down, up, right
2. `w`: beginning of the next word  
   `W`: beginning of the next word (split by space)
3. `e`: ending of the next word  
   `E`: ending of the next word (split by space)  
4. `b`: beginning of the previous word  
   `B`: beginning of the previous word (split by space)
5. `f{char}`: find the {char} in the line  
   `F{char}`: find the previous {char} in the line  
   `;`: jump to the next {char}  
   `,`: jump to the previous {char}  
6. `0`: go to the first character in the line  
   `^`: go to the first non-empty character in the line  
   `$`: go to the last character in the line  
   `g_`: go to the last non-empty character in the line  
   Tips: `0w`: go to the first non-empty character in the line
7. `gg`: go the beginning of the file
    `G`: go to the end of the file
8. `H/L/M`: Head, Middle, and Lower
9. `ctrl+u`: last page  
   `ctrl+f`: next page  
   `zz`: put the current line in the middle
10. `:help (`: check the instruction of "("

# Class 2-5
## NORMAL mode
1. `x`: delete a character
2. `d`: delete a word
   - `num+x/d/dd`: excute delete num of times
   - `daw`: delete around the word (delete the space)
   - `diw`: delete in the word (keep the space)
   - `dd`: delete the line`
   - `dt)`: delete to ")"
   - `d$`: delete to the end
   - `d0`: delete to the beginning
3. `r{char}`: replace {char} to the current character  
   `R{char}`: replace character by character
4. `s`: delete (substitute) and convert to INSERT mode  
   `S`: detete the whole line and convert to INSERT mode  
5. `c`: delete (change) and convert to INSERT mode (need to work with w, t...)  
   `cw`: change the word  
   `ct"`: change to "  
## VISUAL mode
1. `v+l+d`: start select by v, move to right by l, then delete by d

# Class 2-6
## COMMAND mode
1. `:[range]s[ubstitute]/{pattern}/{string}/[flags]`
   - range:
      - `:10,20`: from line 10 to 20
      - `%`: all
   - flags:
      - `g`: global
      - `c`: confirm
      - `n`: number (ONLY check the number of time)
   - examples:
      - `:% s/self/this/g`
      - `:1,6 s/self/this/g`
      - `:1,6 s/self//n`
      - `:% s/quack/jiao/g`: substitute all quack with jiao, even change a word including quack. e.g. changing "do_quack" to "do_jiao"
      - `:% s/\<quack\>/jiao/g`: exactly checking "quack". e.g. keep "do_quack" unchanged

# Class 2-7
## COMMAND mode
1. `:ls`: shows all buffers  
   `:e b.txt`: edits "b.txt" file
   `b 1`: jumps to the first buffer  
   `b c.txt`: jumpts to the buffer with the file named "c.txt"
2. Window
   - `<Ctrl+w> s`: same as `:sp`
   - `<Ctrl+w> v`: same as `:vs`
   - `<Ctrl+w> w`: jumps to the next window
   - `<Ctrl+w> h/j/k/l`: jumps to the left/below/above/right window
   - `<Ctrl+w> H/J/K/L`: moves the window to left/below/above/right
3. Tab
   - `:tabnew duck.py`: opens a new tab with duck.py file
   - `:vs hello.py`: opens the hello.py file in the same tab
   - `gt`: jumps to the next tab

# Class 2-8
1. [number]<command>[text object]
   - number: the number of times for the command
   - command: d(delete), c(change), y(yank)
   - text object: w(word), s(sentence), p(paragraph)

# Class 2-9
## NORMAL mode
1. Copy and Paste
   - v(visual): select
   - y(yank): copy
   - p(put): paste
   - d(delete): cut
2. yiw(copy a word), yy(copy a line) 
## INSERT mode
1. Copy and Paste
   - `Ctrl+v`
2. Within _autoindent_, fix the bug by using `:set paste` && `:set nopaste`
## Register
1. `"ayiw`: using register "a" to copy the word
2. `"bdd`: using register "b" for the deleted line
3. `:reg a`: checks what are in the register "a"
4. `"0`: register that only for copy
5. `"+`: copies to the system clipboard
   - `:echo has('clipboard')`: checks if vim support system clipboard
      - "1" means support, "0" means not
   - `:set clipboard=unnamed`: set clipboard works with unnamed register
