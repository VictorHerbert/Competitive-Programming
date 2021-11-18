import os
import filecmp as f
import sys

from termcolor import colored 


MSG_SIZE = 40
ok_msg = lambda s : colored((' ' + s + ' ').center(MSG_SIZE,'='), color = 'green', attrs=['bold'])
fail_msg = lambda s : colored((' ' + s + ' ').center(MSG_SIZE,'='), color = 'red', attrs=['bold'])
hint_msg = lambda s : colored((' ' + s + ' ').center(MSG_SIZE,'='), color = 'blue', attrs=['bold'])
ok = lambda s : colored(s, color = 'green', attrs=['bold'])
fail = lambda s : colored(s, color = 'red', attrs=['bold'])
hint = lambda s : colored(s, color = 'blue', attrs=['bold'])
hint_white = lambda s : colored(s, color = 'white', attrs=['bold'])

if not f.cmp('main.cpp', 'generated\\~main.cpp'):
    if os.system('g++ -std=c++17 main.cpp -o generated\\s.exe') == 0:
        os.system('del generated\\~main.cpp')
        os.system('copy main.cpp generated\\~main.cpp >nul')

        print(ok('Using compiled version'))
    else:
        print(hint_white('Using cached version'))
else:
    print(hint_white('Using cached version'))


if '--c' in sys.argv or '-check' in sys.argv:
    error_count = 0
    error_map = dict()
    print()
    print(hint_msg('Tests'))

    for in_name in os.listdir('input\\'):        
        try:
            out_name = in_name.replace('in','out')

            os.system(f'generated\\s.exe < input\\{in_name} > output\\{out_name}')

            out_file = open(f'output\\{out_name}')
            out_file_check = open(f'output\\check\\{out_name}')

            out = out_file.read().split('\n')
            out_check = out_file_check.read().split('\n')

            index = in_name.replace('in','').replace('.txt','')
            print(f'Case {index}: ', end='')
            if len(out) == len(out_check):
                for j in range(len(out)):
                    if out[j] == out_check[j]:
                        print(ok('.'), end='')
                    else:
                        print(fail('x'), end='')
                        if index in error_map:
                            error_map[index].append((j, out[j], out_check[j]))
                        else:
                            error_map[index] = [(j, out[j], out_check[j])]
                        
                        error_count +=1
                    
            else:
                print('Sizes doesn\'t match')
                error_count += 1

            print()
        except FileNotFoundError as e:
            break

    if error_count == 0:
        print(ok_msg('All tests passed'))
    else:
        plural = '' if error_count == 1 else 's'

        print()
        print(fail_msg(f'{error_count} error{plural} found'))
        print(hint_msg('Summary'))
        print()
        for case, error_list in error_map.items():
            for error in error_list:
                print(f'Case {case} | line {error[0]} | {error[1]} -> {error[2]}')
else:
    os.system(f'generated\\s.exe < input\\in1.txt > output\\out1.txt')
