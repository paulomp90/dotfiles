-- Pull in the wezterm API
local wezterm = require 'wezterm'

-- local bar = wezterm.plugin.require "https://github.com/adriankarlen/bar.wezterm"

local config = {}

if wezterm.config_builder then
  config = wezterm.config_builder()
end

local act = wezterm.action
-- This is where you actually apply your config choices

config = {
    audible_bell = "Disabled",
    -- color_scheme = 'AdventureTime',

    -- Font
    font = wezterm.font 'JetBrains Mono NL',
    font_size = 15,

    -- Colors
    colors = {
		-- The default text color
		-- foreground = colors["linkarzu_color14"],
		foreground = '#eff0eb',
		-- The default background color
		-- background = colors["linkarzu_color10"],
		background = '#282a36',

		-- Overrides the cell background color when the current cell is occupied by the cursor
		-- cursor_bg = colors["linkarzu_color14"],
        cursor_bg = '#97979B',
		-- Overrides the text color when the current cell is occupied by the cursor
		-- cursor_fg = colors["linkarzu_color10"],
		-- Specifies the border color of the cursor when the cursor style is set to Block
		-- cursor_border = colors["linkarzu_color02"],

		-- The foreground color of selected text
		-- selection_fg = colors["linkarzu_color14"],
		selection_fg = '#000000',
		-- The background color of selected text
		-- selection_bg = colors["linkarzu_color16"],
		selection_bg = '#FFFACD',

		-- The color of the scrollbar "thumb"; the portion that represents the current viewport
		-- scrollbar_thumb = colors["linkarzu_color10"],

		-- The color of the split lines between panes
		-- split = colors["linkarzu_color02"],
        split = '#97979B',

		-- ANSI color palette
		ansi = {
			-- colors["linkarzu_color10"], -- black
            '#282a36',
			-- colors["linkarzu_color11"], -- bright red
            '#FF5C57',
			-- colors["linkarzu_color02"], -- bright green
            '#5AF78E',
			-- colors["linkarzu_color05"], -- bright yellow
            '#F3F99D',
			-- colors["linkarzu_color04"], -- bright blue
            '#57C7FF',
			-- colors["linkarzu_color01"], -- bright magenta
            '#FF6AC1',
			-- colors["linkarzu_color03"], -- bright cyan
            '#9AEDFE',
			-- colors["linkarzu_color14"], -- bright white
            '#EFF0EB',
		},

		-- Bright ANSI color palette
		brights = {
			-- colors["linkarzu_color08"], -- bright black
            '#686868',
			-- colors["linkarzu_color11"], -- bright red
            '#FF5C57',
			-- colors["linkarzu_color02"], -- bright green
            '#5AF78E',
			-- colors["linkarzu_color05"], -- bright yellow
            '#F3F99D',
			-- colors["linkarzu_color04"], -- bright blue
            '#57C7FF',
			-- colors["linkarzu_color01"], -- bright magenta
            '#FF6AC1',
			-- colors["linkarzu_color03"], -- bright cyan
            '#9AEDFE',
			-- colors["linkarzu_color14"], -- bright white
            '#F1F1F0',
		},
	},

    -- Keys
    keys = {
        -- { key = "Tab", mods = "CTRL", action = act.ActivateTabRelative(1) },
	    -- { key = "Tab", mods = "SHIFT|CTRL", action = act.ActivateTabRelative(-1) },
        { key = 'v', mods = "CTRL", action = act.SplitVertical({ domain = "CurrentPaneDomain" }) },
        { key = "h", mods = "CTRL", action = act.SplitHorizontal({ domain = "CurrentPaneDomain" }) },
        { key = "w", mods = "CTRL|SHIFT", action = act.CloseCurrentTab({ confirm = false }) },
        { key = "w", mods = "CTRL", action = act.CloseCurrentPane({ confirm = false }) },
		{ key = 'w', mods = 'CMD', action = wezterm.action.DisableDefaultAssignment },
		-- Cycle to the next pane
		{ key="l", mods="CTRL", action=wezterm.action{ActivatePaneDirection="Next"}},
		-- Cycle to the previous pane
		{ key="j", mods="CTRL", action=wezterm.action{ActivatePaneDirection="Prev"}},

        -- { key = "c", mods = "CTRL", action = act.CloseCurrentPane({ confirm = false }) },

    },

    -- Tab/Status Bar
    use_fancy_tab_bar = false,
    show_new_tab_button_in_tab_bar = false,
    hide_tab_bar_if_only_one_tab = true,
    status_update_interval = 1000,
    tab_max_width = 60,

    -- Initial window size
    initial_rows = 50,
    initial_cols = 160,


    scrollback_lines = 7000,
    window_close_confirmation = 'NeverPrompt',
}
-- tests
-- bar.apply_to_config(config, {spotify = false, clock=false})

-- and finally, return the configuration to wezterm

return config
