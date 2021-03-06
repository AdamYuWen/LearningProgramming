# Git Command
## Create Git
1. `git init`, `git clone`
2. `git config --global user.name "name"`
   `git config --global user.email "email"`
## Commit to Git and Push to Remotes
1. `git status`, `git add`, `git commit`, `git log`, `git diff`
   - `git add .`: add all files
   - `git commit -m "message"`: create a short commit message
   - `git commit`: open editor and edit commit message
   - `git add <file_name>; git commit -m "message"`: combine add and commit
   - `git commit -am "message"`: combine add and commit
   - `git log -- <file_name>`: shows the log only for the file (MUST include a space after --)
   - `git diff`: ONLY show the tracked files
   - `git diff --staged`: shows the differences between Staging Area and History (after add, before commit)
## Rewriting Git History
1. Amend: `git add .` and `git commit --amend --no-edit`
2. Reword: `git rebase -i HEAD~3` and change "pick" to "reword" (i means interactive)
3. Delete: `git rebase -i HEAD~3` and change "pick" to "drop"
4. Reorder: `git rebase -i HEAD~3` and change the order of commits
5. Squash: `git rebase -i HEAD~3` and change "pick" to "fixup"
6. Split:
   - `git rebase -i HEAD~3`
   - change "pick" to "edit"
   - `git reset HEAD^`
   - `git add <file_name>`
   - `git commit -m "message"`
   - Redo last two items
## Undo
1. - `git checkout .` or `git reset --hard`: before add
   - `git reset` and `git checkout .` or `git reset --hard`: after add (After `git reset`, move files to before add (have the modified files). After `git checkout .`, remove all changes.) (`git reset --hard` conbine previous two steps)
   - `git reset --hard origin/master`: after commit
   - `git reset --hard HEAD~1` and `git push -f`: after push, remove the latest commit in both local and remote
2. `git checkout`, `git clean`, `git reset`
   - `git checkout -- <file_name>`: undo the file in Working Tree (before add) (MUST include a space after --)
   - `git checkout <commit_hash> -- <file_name>`: checkout the file from a certain commit (The file will directly be in Staging Area (after add, before commit))
   - `git checkout -f` or `git checkout -- .`: removes all uncommitted changes for tracked files
   - `git clean -fd`: removes all uncommited changes for untracked files
   - `git reset HEAD <file_name>`: undo the files in Staging Area (after add, before commit (still have the modified files)
   - `git fetch --all`, `git reset --hard origin/master`, `git pull`: undo local files and download files from remote (after commit, before push)
3. `git merge --abort`: undo the merge
4. `git reset --soft HEAD~1`: remove previous commit and back to after add
5. `git reset --hard HEAD~1`: remove previous commit and remove all changes
6. `git reset --mixed HEAD~1`: remove previous commit and back to before add
## Branch
1. `git branch`
   - `git branch`: shows branches and which branch is checking out
   - `git branch <branch_name>`: create a new branch
   - `git checkout <branch_name>`: check out the branch
   - `git checkout -b <branch_name>`: combine the previous two command
2. `git merge`
   - `git diff master..<branch_name>`: gets the differences between two branches
   - `git merge <branch_name>`
     - fast-forward merge: If the branch has a direct path the the master, git will move master and HEAD to the merged branch.
     - 3-Way merge (`git merge <branch_name> --no-ff`)
   - `git branch --merged`: checks which branches are merged
   - `git branch -d <branch_name>`: deletes local branches
   - `git push origin --delete <branch_name>`: deletes remote branches
   - `git fetch --all -prune`: after deleting remote branches, updated the branches on other machines (It only update branches. It won't delete local branches.)
   - `git merge --abort`: undo the merge
3. `git stash`
   - Modified some files and want to check out another branch, so save the modified files into stash. (It can be done many times.)
   - `git stash list`: gives the list of stash
   - `git stash list -p`: gives more information
   - `git stash apply`: applies the most recent stash
   - `git stash apply <label>`: applies the labeled stash
   - `git stash save "message"`: adds a more meaningful stash message
## Detached HEAD
1. `git checkout <commit_hash>`: detached HEAD
   - Put a new branch on the commit by using `git branch <branch_name>`, but the HEAD doesn't attach to it.
   - `git checkout <branch_name_created_previously>`, the HEAD attaches to it.
2. `git checkout master`: removes the detached HEAD
## Change Branch Names
```
$ git branch -m old_branch new_branch         # Rename branch locally
$ git push origin :old_branch                 # Delete the old branch
$ git push --set-upstream origin new_branch   # Push the new branch, set local branch to track the new remote
```
## Change Files
1. `git rm`, `git mv`
   - `git rm <file_name>`: removes files from Working Tree **and** Staging Area (NOT commit yet)
   - `git mv <old_file_name> <new_file_name>`: changes file name
   - `for f in * ; do git mv -- "$f" "0$f" ; done`: adds prefix ("0" for this case) to all files (works in Git BASH)
## Work with Remotes
1. `git fetch`, `git pull`, `git push`, `git remote`
   - `git fetch origin`: finds new commits and brings them down
   - `git merge origin/master`: merge origin/master to local, fast-forward merge)
   - `git pull`: combine `git fetch` and `git merge`
   - `git remote`: shows origin
   - `git remote -v`: shows full locations
   - `git push origin master`
   - `git push -u origin <branch_name>`: push local branch to remote
2. `git remote`
   - `git remote add <remote_name, e.g. upstream> <git_SSH>`
   - `git remote -v`
   - `git remote remove <remote_name>`
3. Sync with upstream
   - `git fetch <remote_name, e.g. upstream>`
   - `git merge upstream/master`: merge upstream/master to local
   - `git push origin master`
4. After fork, create a new branch
   - `git checkout -b <branch name>`
   - `git branch`: shows local branches ONLY
   - `git branch -a`: shows local and remote branches
   - `git branch -r`: shows remote branches ONLY
5. A new branch is ahead of forked remote
   - `new pull request`
   - send the forked remote a pull request
## Create Tags
1. `git tag -a v2.1.0 -m "xyz feature is released in this tag."`: annotated tags
2. `git tag v2.1.0`: lightweight tags
3. `git push --tags`: pushs all tags
4. `git tag`: lists all tags
# Terminology
**HEAD**: shows which branch we checked out  
**origin**: a shorthand name for the remote repository
# Git Alises
```
$ git config --global alias.br branch
$ git config --global alias.st status
$ git config --global alias.ci commit
$ git config --global alias.co checkout
$ git config --global alias.adog "log --all --decorate --oneline --graph"
```
# Reference:
1. [Introduction to Git - Core Concepts](https://www.youtube.com/watch?v=uR6G2v_WsRA)
2. [Introduction to Git - Branching and Merging](https://www.youtube.com/watch?v=FyAAIHHClqI)
3. [Introduction to Git - Remotes](https://www.youtube.com/watch?v=Gg4bLk8cGNo)
4. [How to rename git local and remote branches](https://www.w3docs.com/snippets/git/how-to-rename-git-local-and-remote-branches.html)
5. [Create a tag in a GitHub repository](https://stackoverflow.com/questions/18216991/create-a-tag-in-a-github-repository)
6. [Git ignore local file changes](https://stackoverflow.com/questions/24983762/git-ignore-local-file-changes/24983863)
7. [How can I delete branches in Git?](https://www.git-tower.com/learn/git/faq/delete-remote-branch)
8. [Rewriting Git History - Amend, Reword, Delete, Reorder, Squash and Split](https://www.youtube.com/watch?v=ElRzTuYln0M)
9. [How To Undo Last Git Commit](https://devconnected.com/how-to-undo-last-git-commit/)
