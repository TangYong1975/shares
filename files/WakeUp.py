import win32api, win32con
import time
import pyautogui

def run():
  loc = win32api.GetCursorPos()
  win32api.SetCursorPos((loc[0], loc[1]))
  win32api.mouse_event(win32con.MOUSEEVENTF_LEFTDOWN, loc[0], loc[1], 0, 0)
  win32api.mouse_event(win32con.MOUSEEVENTF_LEFTUP, loc[0], loc[1], 0, 0)

def run_autogui():
  x, y = pyautogui.position()
  pyautogui.moveTo(x, y)

while True:
  run_autogui()
  time.sleep(2)