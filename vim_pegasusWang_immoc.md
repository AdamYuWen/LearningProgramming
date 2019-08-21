# Class 2-1
1. Convert NORMAL mode to INSERT mode (a, i, o)
   - `a`: append
   - `i`: insert
   - `o`: open a new line below
   - `A`: append at the end of the line
   - `I`: insert at the beginning of the line
   - `O`: open a new line above
2. Convert INSERT mode to NORMAL mode (ESC)
3. `:q` quit
4. `:wq` written and quit

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