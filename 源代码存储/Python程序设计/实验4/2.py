def print_menu(menu, level=1):
  for key in menu:
    print(f"{'  ' * (level - 1)}{key}")
    if isinstance(menu[key], dict):
      print_menu(menu[key], level + 1)

def navigate_menu(menu):
  current_menu = menu
  path = []

  while True:
    print("\n当前菜单:")
    print_menu(current_menu)
    choice = input("\n请输入您的选择（或输入 'back' 返回上一级，'exit' 退出程序）: ").strip()

    if choice == 'exit':
      break
    elif choice == 'back':
      if path:
        current_menu = path.pop()
      else:
        print("您已经在顶级菜单。")
    elif choice in current_menu:
      if isinstance(current_menu[choice], dict):
        path.append(current_menu)
        current_menu = current_menu[choice]
      else:
        print(f"您选择了: {current_menu[choice]}")
    else:
      print("无效选择。请重试。")

if __name__ == "__main__":
  data = {
    '江西省':{
      '南昌市':{
        '大学':{"南昌大学","东华理工大学","江西农业大学"},
        '中学':{"南昌一中","南昌二中","南昌三中"},
      },
      '吉安市':{
        '大学':{"井冈山大学"},
        '中学':{"吉安一中","吉安二中"},
      }
    },
    '北京市':{
      '海淀区':{
        '大学':{"北京大学","清华大学"},
        '中学':{"海淀一中","海淀二中"},
      },
      '朝阳区':{
        '大学':{"中央财经大学","北京外国语大学"},
        '中学':{"朝阳一中","朝阳二中"},
      }
    }
  }

  navigate_menu(data)