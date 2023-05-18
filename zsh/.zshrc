#!/usr/bin/env zsh

export LC_ALL=en_US.UTF-8
export LANG=en_US.UTF-8

# Turn off all beeps
unsetopt BEEP

# History
setopt SHARE_HISTORY             # Share history between all sessions.

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

zsh_add_file "$ZSHPATH/.zshfunctions"
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

export PATH="$PATH:$HOME/.yarn/bin"

# FZF
# Setting fd as the default source for fzf
export FZF_DEFAULT_COMMAND='fd --type f --strip-cwd-prefix'

# fzf with preview
[ -f ~/.fzf.zsh ] && source ~/.fzf.zsh
  alias fzfp="fzf --preview 'bat --style=numbers --color=always --line-range :100 {}'"

[ -s "$HOME/.config/envman/load.sh" ] && source "$HOME/.config/envman/load.sh"
