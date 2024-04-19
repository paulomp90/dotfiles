#!/usr/bin/env zsh

export LC_ALL=en_US.UTF-8
export LANG=en_US.UTF-8

# Turn off all beeps
unsetopt BEEP

####### History
setopt SHARE_HISTORY         # Share history between all sessions.
setopt HIST_IGNORE_DUPS      # Hist to ignore duplications

eval $(/opt/homebrew/bin/brew shellenv)
eval "$(fnm env --use-on-cd)"

# Completions
zstyle ':completion:*' menu select
zstyle ':completion:*' list-colors "${(s.:.)LS_COLORS}"

autoload -U compinit; compinit

# pure
fpath+=("$(brew --prefix)/share/zsh/site-functions")
autoload -U promptinit; promptinit
prompt pure

PURE_PROMPT_SYMBOL='➜'
zstyle ':prompt:pure:prompt:success' color green
zstyle :prompt:pure:git:stash show yes


# Useful Functions
source "$ZSHPATH/zsh-functions"

zsh_add_file "$ZSHPATH/.zshutils"
zsh_add_file "$ZSHPATH/.zshaliases"

# Plugins
zsh_add_plugin "zsh-users/zsh-autosuggestions"
zsh_add_plugin "zsh-users/zsh-syntax-highlighting"

# zsh-autosuggestions
ZSH_AUTOSUGGEST_HIGHLIGHT_STYLE="fg=#767676"
ZSH_AUTOSUGGEST_CLEAR_WIDGETS+=(bracketed-paste)


# export NVM_DIR="$HOME/.nvm"
#   [ -s "$NVM_DIR/nvm.sh" ] && \. "$NVM_DIR/nvm.sh"  # This loads nvm
#   [ -s "$NVM_DIR/bash_completion" ] && \. "$NVM_DIR/bash_completion"  # This loads nvm bash_completion

#export PATH="$(yarn global bin):$PATH"
#export PATH="$PATH:$HOME/.yarn/bin"

[ -s "$HOME/.config/envman/load.sh" ] && source "$HOME/.config/envman/load.sh"

####### FZF
# Setting fd as the default source for fzf
# show hidden files and exclude git ignore
export FZF_DEFAULT_COMMAND='fd --hidden --strip-cwd-prefix --exclude .git'
export FZF_CTRL_T_COMMAND="$FZF_DEFAULT_COMMAND"


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

# Webstorm
#export PATH="/Applications/WebStorm.app/Contents/MacOS:$PATH"
