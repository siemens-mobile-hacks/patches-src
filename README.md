### add_icons_to_header_in_nm
Добавление иконок в заголовок Native Menu.

### battery_percentage_instead_of_icons
Отображение заряда батареи вместо иконок.

### change_network_search_text
Заменяет текст "Поиск сети" на "Сеть недоступна", если отключен поиск сети.
Патч работает на главном экране и заставке.

### disable_network
Отключение поиска сети, если телефон загружен без сим-карты.

### display_message_instead_of_starting_a_java_application_if_jam_is_disabled
Если Java машина отключена и попытаться запустить любое Java приложение, то создается "пустой" CSM и течет память при каждой попытке запуска.
Теперь вместо этого отображается сообщение "Java is disabled!", память больше не течет!

### fix_network_icon
Добавляет иконку сети специально для режима при котором отключена сеть.

### open_disk_selection_menu_in_ce_by_hotkey
Открывает меню выбора дисков по зеленой кнопке в Card Explorer.

### set_dir_of_theme_resources
По умолчанию ресурсы тем сохраняются в каталоги **0:\Pictures**, **0:\Sounds** и тем самым загрязняют их.
Данный патч переносит запись в директорию **1:\ThemeResources**. Перед применением темы каталог **1:\ThemeResources** очищается.

### show_error_message_if_browser_could_not_start
Добавлены некоторые сообщения об ошибках, если не удалось запустить браузер:
1. Браузер отключен - "Browser is disabled!"
2. Браузер уже запущен - "Browser is already running!"

### using_elfs_screensavers
Патч для замены стандартных скринсейверов телефона на скринсейверы-эльфы.
