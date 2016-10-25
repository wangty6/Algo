#!/usr/bin/python
import subprocess
import os
code_dir = "code"
title = "Stanford ACM-ICPC Team Notebook"

def get_sections():
    sections = []
    section_name = None
    for path, dirs, files in os.walk(code_dir):
        subsections = []
        section_name = os.path.basename(path)
        sections.append((section_name, subsections))
        for f in files:
            subsections.append((section_name + '/' + f, f[:f.find('.')]))
    print(sections)
    return sections

def get_style(filename):
    ext = filename.lower().split('.')[-1]
    if ext in ['c', 'cc', 'cpp']:
        return 'cpp'
    elif ext in ['java']:
        return 'java'
    elif ext in ['py']:
        return 'py'
    else:
        return 'txt'

# TODO: check if this is everything we need
def texify(s):
    s = s.replace('\'', '\\\'')
    s = s.replace('\"', '\\\"')
    s = s.replace('&', '\&')
    s = s.replace('_', '\_')
    return s

def get_tex(sections):
    tex = ''
    for (section_name, subsections) in sections:
        tex += '\\section{%s}\n' % texify(section_name)
        for (filename, subsection_name) in subsections:
            tex += '\\subsection{%s}\n' % texify(subsection_name)
            tex += '\\raggedbottom\\lstinputlisting[style=%s]{%s/%s}\n' % (get_style(filename), code_dir, filename)
            tex += '\\hrulefill\n'
        tex += '\n'
    return tex

if __name__ == "__main__":
    sections = get_sections()
    tex = get_tex(sections)
    with open('contents.tex', 'w') as f:
        f.write(tex)
    latexmk_options = ["latexmk", "-pdf", "notebook.tex"]
    subprocess.call(latexmk_options)
