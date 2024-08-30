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

ln -sfnv /Users/paulopereira/Projects/dotfiles/zsh/.zshrc /Users/paulopereira/.zshrc &&
ln -sfnv /Users/paulopereira/Projects/dotfiles/git/.gitconfig ~/.gitconfig
ln -sfnv /Users/paulopereira/Projects/dotfiles/config/starship.toml ~/.config/starship.toml
ln -sfnv /Users/paulopereira/Projects/dotfiles/config/kitty.conf ~/.config/kitty/kitty.conf