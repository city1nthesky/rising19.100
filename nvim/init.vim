let mapleader=" "
set autochdir

"Editor behavior
syntax on
set number
set relativenumber
set cursorline
set wrap
set showcmd
set wildmenu
set hlsearch
exec "nohlsearch"
set incsearch
set ignorecase
set smartcase
set tabstop=4
set shiftwidth=4
set softtabstop=4

"colorscheme snazzy
"let g:SnazzyTranspart = 1 let g:lightkine = {'colorscheme': 'snazzy'}

"config airline
set laststatus=2  "show status bar
let g:airline_powerline_fonts = 1 "support powerline font
let g:airline#extensions#tabline#enabled = 1 "show windowtab and buffer
let g:airline_theme='moloai'
if !exists('g:airline_symbols')
let g:airline_symbols = {}
endif
let g:airline_left_sep = '▶'
let g:airline_left_alt_sep = '❯'
let g:airline_right_sep = '◀'
let g:airline_right_alt_sep = '❮'
let g:airline_symbols.linenr = '¶'
let g:airline_symbols.branch = '⎇'

"config NERDTreeToggle
nnoremap <LEADER>n :NERDTreeFocus<CR>
nnoremap <C-n> :NERDTreeToggle<CR>
nnoremap <C-t> :NERDTree<CR>
nnoremap <C-f> :NERDTreeFind<CR>
"Start NERDTree and leave the cursor in it
"autocmd VimEnter * NERDTree
"Start NERDTree and put the cursor back in the other window
"autocmd VimEnter * NERDTree | wincmd p
"Start NERDTree when Vim is started without file arguments
autocmd StdinReadPre * let s:std_in=1
autocmd VimEnter * if argc() == 0 && !exists('s:std_in') | NERDTree | wincmd p
" Exit Vim if NERDTree is the only window remaining in the only tab.
autocmd BufEnter * if tabpagenr('$') == 1 && winnr('$') == 1 && exists('b:NERDTree') && b:NERDTree.isTabTree() | quit | endif

"config fzf
nnoremap <LEADER>f :FZF<CR>

"config nvim custom key
noremap <LEADER><CR> :nohlsearch<CR>
noremap <LEADER>- /\^-\^<CR>

map S :w<CR>
map s <nop>
map Q :q<CR>
map R :source ~/.config/nvim/init.vim<CR>
map n nzz
noremap j 5jzz
noremap k 5kzz
noremap J j
noremap K k

inoremap case switch(^-^)<CR>{<CR>case ^-^:<CR>break;<CR><CR>default :<CR>break;<CR>}<ESC>i




call plug#begin('~/.config/nvim/plugged')
Plug 'neoclide/coc.nvim',{'branch': 'release'}
"Plug 'neoclide/coc.nvim',{'branch': 'master', 'do': 'yarn install --frozen-lockfile'}
Plug 'preservim/nerdtree'
Plug 'jiangmiao/auto-pairs'
Plug 'vim-airline/vim-airline'
Plug 'vim-airline/vim-airline-themes'


Plug 'connorholyday/vim-snazzy'


Plug 'junegunn/fzf', {'do': { -> fzf#install() }}

call plug#end()
