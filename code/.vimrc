set nocp nu cin ts=4 sw=4
syn on
set mp=g++\ -g\ -o\ %<\ %\ -Wall\ -std=c++11
map mk :make<CR>
map mr :!./%<<CR>
map mw :!./%< < %<.in<CR>
map mi :sp %<.in<CR>
