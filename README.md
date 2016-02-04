### Assignment 2
##### Config File Generator
We are going to start our long term project for this semester with a tool that will manage a settings or configuration file that the rest of our programs will use to configure themselves.

It is very likely this program will change often so attention to detail and good coding habbits will make your life much easier in the future.

##### Here is what you will build:
###### Config File Generator
A configuration file is usually a human readable file that holds the information for how an application or suite of applications will work. Lets take a look at a config file you already have as an example:
```txt
[user]
	email = paul.scarrone@gmail.com
	name = Paul Scarrone
[merge]
	tool = sublime
[alias]
  pretty = log --graph --pretty=format:'%Cred%h%Creset -%C(yellow)%d%Creset %s %Cgreen(%cr) %C(bold blue)<%an>%Creset' --abbrev-commit --date=relative
  cleanup = "!git branch --merged | grep  -v '\\*\\|master\\|develop' | xargs -n 1 git branch -d"
[core]
	editor = eval $SUBL -n -w
	excludesfile = /Users/samuraipanzer/.gitignore_global
[mergetool "sublime"]
	cmd = eval $SUBL -w $MERGED
	trustExitCode = false
[push]
	default = simple
[filter "lfs"]
	clean = git-lfs clean %f
	smudge = git-lfs smudge %f
	required = true
[difftool "sourcetree"]
	cmd = opendiff \"$LOCAL\" \"$REMOTE\"
	path =
[mergetool "sourcetree"]
	cmd = /Applications/SourceTree.app/Contents/Resources/opendiff-w.sh \"$LOCAL\" \"$REMOTE\" -ancestor \"$BASE\" -merge \"$MERGED\"
	trustExitCode = true
```
The above is a `.gitconfig` file it is how git knows who you are and how it should do its job. Items like `[merge]` and `[user]` are section headers and indented lines below are the configurations for that section.
Your file does not need to look like this. There are a great number of standards for config files. JSON, YAML, XML, and custom ones just to name a few.

Your program will act in two ways first it will accept the `init` and `edit` arguments:
- When the `init` argument is used the program will ask a series of questions
  1. Enter your name
  2. Enter your email address
  3. Enter your unique cypher(don't user your real password just make something up)
  4. Enter your timezone-offset(probably -5:00 for all of us)
  5. Enter path to knownrecipients file:
  - If the user fails to enter a value for any of these fields it should prompt them and ask them to enter the input again with the exception of the last field.
  - If the user does not enter the knownrecipients path provide a default that is in the same directory as the file was executed.
- When the `edit` arguemnt is used it must also include a field to edit eg: Assuming our program is called `gen` `gen edit name`


##### How to write the program:
- Use the full definition of the `main` function for your program entry point `int main(int argc, char *argv[])` this variant allows your program to accept arguments from the command line
- Update you `Build Configuration` to pass some arguments to your program on run to make testing easier. See the included image
- To access your arguments you are going to need use _array_ syntax. `argv` is the array that contains the arguments and this is how they are ordered
  1. arg 0 is the execution path of the file
  2. arg 1 is the first argument `argument1` accessible with `argv[0]`
  3. arg 2 is the second argument `argument2` accessible with `argv[0]`
  4. this keeps going on if there are more arguments accessible with `argv[<a number>]`

