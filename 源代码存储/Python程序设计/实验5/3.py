import string

def count_characters(file_content):
  upper_case = sum(1 for c in file_content if c.isupper())
  lower_case = sum(1 for c in file_content if c.islower())
  digits = sum(1 for c in file_content if c.isdigit())
  whitespace = sum(1 for c in file_content if c.isspace())
  others = len(file_content) - upper_case - lower_case - digits - whitespace
  return upper_case, lower_case, digits, whitespace, others

def count_words(file_content):
  translator = str.maketrans(string.punctuation, ' ' * len(string.punctuation))
  cleaned_content = file_content.translate(translator)
  words = cleaned_content.split()
  return len(words)

def calculate_offset(secret_word):
  ascii_sum = sum(ord(c) for c in secret_word)
  offset = ascii_sum % 26
  return offset

def caesar_cipher(file_content, offset):
  def shift_char(c):
    if c.isalpha():
      base = ord('A') if c.isupper() else ord('a')
      return chr((ord(c) - base + offset) % 26 + base)
    return c

  encrypted_content = ''.join(shift_char(c) for c in file_content)
  return encrypted_content

def main():
  import os
  #获取运行时的路径
  path = os.path.split(os.path.realpath(__file__))[0]+'\\'
  print('文件执行路径为:'+path)
  file_path = path+'\\mayun.txt'  # Replace with the actual file path
  secret_word = input("请输入一个代表星期几的单词：")

  with open(file_path, 'r', encoding='utf-8') as file:
    file_content = file.read()

  upper_case, lower_case, digits, whitespace, others = count_characters(file_content)
  word_count = count_words(file_content)
  offset = calculate_offset(secret_word)
  encrypted_content = caesar_cipher(file_content, offset)

  print(f"大写字母数量: {upper_case}")
  print(f"小写字母数量: {lower_case}")
  print(f"数字数量: {digits}")
  print(f"空白字符数量: {whitespace}")
  print(f"其他字符数量: {others}")
  print(f"单词数量: {word_count}")
  print(f"偏移量: {offset}")
  print(f"加密结果: {encrypted_content}")

if __name__ == "__main__":
  main()