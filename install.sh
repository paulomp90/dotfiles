#!/usr/bin/env zsh

# Install Homebrew
function brew_install {
    /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"

    cd ./homebrew && brew bundle --force cleanup --file=Brewfile


#     os_type="$(uname -s)"

#     if [ "${os_type}" == "Darwin" ]; then
#         brew bundle --force cleanup --file=BrewfileMac
#     fi
}

[ -x "$(command -v brew > /dev/null 2>&1)" ] && brew_install

# rm -rf $HOME/.zshrc
# rm -rf $HOME/.zshenv
# rm -rf $HOME/.gitconfig

ln -sfnv $ZSHPATH/.zshenv $HOME/.zshenv &&
ln -sfnv $ZSHPATH/.zshrc $HOME/.zshrc &&
ln -sfnv $PROJECT/dotfiles/git/.gitconfig ~/.gitconfig


# source ~/.zshenv
# source ~/.zshrc
 