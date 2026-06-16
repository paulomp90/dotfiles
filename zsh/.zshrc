#!/usr/bin/env zsh

export LC_ALL=en_US.UTF-8
export LANG=en_US.UTF-8

# Turn off all beeps
unsetopt BEEP

####### History
HISTSIZE=100000          # commands kept in memory for current session
SAVEHIST=100000          # commands saved to history file
HISTFILE=~/.zsh_history  # location (default is fine)

setopt APPEND_HISTORY        # append, don't overwrite
setopt INC_APPEND_HISTORY    # write as commands run, not just on exit
setopt SHARE_HISTORY         # share history across sessions
setopt HIST_IGNORE_DUPS      # don't record consecutive dupes
setopt HIST_IGNORE_ALL_DUPS  # remove older dupes
setopt HIST_REDUCE_BLANKS    # trim extra whitespace

autoload -U compinit; compinit

# Completions
zstyle ':completion:*' menu select
zstyle ':completion:*' list-colors "${(s.:.)LS_COLORS}"

eval $(/opt/homebrew/bin/brew shellenv)

####### ZSH Useful Functions
source "$ZSHPATH/zsh-functions"

zsh_add_file "$ZSHPATH/.zshutils"
zsh_add_file "$ZSHPATH/.zshaliases"

# [ -s "$HOME/.config/envman/load.sh" ] && source "$HOME/.config/envman/load.sh"

####### FZF
# Setting fd as the default source for fzf
# show hidden files and exclude git ignore
export FZF_DEFAULT_COMMAND='fd --hidden --strip-cwd-prefix --exclude .git'
export FZF_CTRL_T_COMMAND="$FZF_DEFAULT_COMMAND"

source <(fzf --zsh)

# Use fd (https://github.com/sharkdp/fd) for listing path candidates.
# - The first argument to the function ($1) is the base path to start traversal
# - See the source code (completion.{bash,zsh}) for the details.
_fzf_compgen_path() {
  fd --hidden --follow --exclude ".git" . "$1"
}

# Use fd to generate the list for directory completion
_fzf_compgen_dir() {
  fd --type d --hidden --follow --exclude ".git" . "$1"
}

# fzf preview
[ -f ~/.fzf.zsh ] && source ~/.fzf.zsh
  alias fzfp="fzf --preview 'bat --style=numbers --color=always --line-range :300 {}'"

# Advanced customization of fzf options via _fzf_comprun function
# - The first argument to the function is the name of the command.
# - You should make sure to pass the rest of the arguments to fzf.
_fzf_comprun() {
  local command=$1
  shift

  case "$command" in
    cd)           fzf --preview 'tree -C {} | head -200'   "$@" ;;
    # export|unset) fzf --preview "eval 'echo \$'{}"         "$@" ;;
    # ssh)          fzf --preview 'dig {}'                   "$@" ;;
    *)            fzf --preview 'bat -n --color=always {}' "$@" ;;
  esac
}


eval "$(fzf --zsh)"

# take a look at https://github.com/junegunn/fzf-git.sh


#-------------------------
eval "$(starship init zsh)"

# Plugins
zsh_add_plugin "zsh-users/zsh-autosuggestions"
zsh_add_plugin "zsh-users/zsh-syntax-highlighting"

# zsh-autosuggestions
ZSH_AUTOSUGGEST_HIGHLIGHT_STYLE="fg=#767676"
ZSH_AUTOSUGGEST_CLEAR_WIDGETS+=(bracketed-paste)

# zsh-syntax-highlight
# ZSH_HIGHLIGHT_STYLES[unknown-token]="fg=red"
# ZSH_HIGHLIGHT_STYLES[path]="none"
eval "$(fnm env --use-on-cd --shell zsh)"

. "$HOME/.local/bin/env"
eval "$(uv generate-shell-completion zsh)"
export PATH="/opt/homebrew/opt/postgresql@17/bin:$PATH"
export PATH="/opt/homebrew/opt/ruby/bin:$PATH"

# React native

# Java
export JAVA_HOME=/Library/Java/JavaVirtualMachines/zulu-17.jdk/Contents/Home

# Android
export ANDROID_HOME=$HOME/Library/Android/sdk
export PATH=$PATH:$ANDROID_HOME/emulator
export PATH=$PATH:$ANDROID_HOME/platform-tools

# IOS
# Add RVM to PATH for scripting. Make sure this is the last PATH variable change.
export PATH="$PATH:$HOME/.rvm/bin"

[[ -s "$HOME/.rvm/scripts/rvm" ]] && . "$HOME/.rvm/scripts/rvm"


# pnpm
export PNPM_HOME="/Users/paulopereira/Library/pnpm"
case ":$PATH:" in
  *":$PNPM_HOME:"*) ;;
  *) export PATH="$PNPM_HOME:$PATH" ;;
esac
# pnpm end
