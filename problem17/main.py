#!/usr/bin/env python

numbers = {
    '1': 'one',
    '2': 'two',
    '3': 'three',
    '4': 'four',
    '5': 'five',
    '6': 'six',
    '7': 'seven',
    '8': 'eight',
    '9': 'nine',
    '10': 'ten',
    '11': 'eleven',
    '12': 'twelve',
    '13': 'thirteen',
    '14': 'fourteen',
    '15': 'fifteen',
    '16': 'sixteen',
    '17': 'seventeen',
    '18': 'eighteen',
    '19': 'nineteen',
    '20': 'twenty',
    '30': 'thirty',
    '40': 'forty',
    '50': 'fifty',
    '60': 'sixty',
    '70': 'seventy',
    '80': 'eighty',
    '90': 'ninety',
    '1000': 'onethousand', # erm =)
}

_sum = 0
for n in xrange(1, 1001):
    sn = str(n)
    if numbers.has_key(sn):
        _sum += len(numbers.get(sn))
    else:
        _decimal = str(int(sn[-2:]))
        if numbers.has_key(_decimal):
            _sum += len(numbers.get(_decimal))
        else:
            _dec = numbers.get(sn[-2] + '0', '')
            _n = numbers.get(sn[-1], '')
            _sum += len(_n) + len(_dec)

        if len(sn) == 3:
            _cent = numbers.get(sn[-3])
            _sum += len(_cent) + 7 # from the "hundred"
            if sn[-2:] != '00':
                _sum += 3 # from the "and"


print _sum


