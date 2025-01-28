import pygame 
import os #用os(operating system)裡面的函式去定義讀取圖檔的路徑(os.path.join())
pygame.font.init()#pygame初始化(initialize)字體模塊(module)
pygame.mixer.init()##pygame初始化(initialize)聲音模塊(module)

WIDTH, HEIGHT = 900, 500#寬跟高
WINDOW = pygame.display.set_mode((WIDTH,HEIGHT))#畫出螢幕寬高
pygame.display.set_caption("Star War")#幫遊戲視窗命名

WHITE = (255,255,255)#白色為R(紅色)亮度255+G(綠色)亮度255+B(藍色)亮度255所合成的。亮度(Luminance)大小定義介於0~255之間
BLACK = (0,0,0)#黑色
RED = (255,0,0)#紅色
YELLOW = (255,255,0)#黃色

FPS = 60#FPS(Frame Per Second)(影格率、幀率的單位(frame rate))(FPS=60表示視窗一秒變化六十次)
SPACESHIP_WIDTH, SPACESHIP_HIEGHT = 55, 40#設定飛船的寬為55，高為40
VELOCITY = 5#速度常數
BULLET_VELOCITY = 10#子彈速度常數
MAX_BULLET = 3#最大彈藥量
BORDER = pygame.Rect(WIDTH//2-5,0,10,HEIGHT)#阻隔長方體,雙斜槓(two slashes)代表計算結果不會有小數點(浮點數,floating point)

HEALTH_FONT = pygame.font.SysFont('comicsans', 40)#設定字體(字體類型,字體大小)
WINNER_FONT = pygame.font.SysFont('comicsans', 100)

YELLOW_HIT = pygame.USEREVENT + 1#自定義事件(撞上黃船)
RED_HIT = pygame.USEREVENT + 2#自定義事件(撞上紅船)

BULLET_HIT_SOUND = pygame.mixer.Sound(os.path.join('Assets','Grenade+1.mp3'))#載入子彈打中敵船的聲音
BULLET_FIRE_SOUND = pygame.mixer.Sound(os.path.join('Assets','Gun+Silencer.mp3'))#載入子彈射出的聲音

YELLOW_SPACESHIP_IMAGE = pygame.image.load(os.path.join('Assets','spaceship_yellow.png'))#載入黃色飛船
RED_SPACESHIP_IMAGE = pygame.image.load(os.path.join('Assets','spaceship_red.png'))#載入紅色飛船
YELLOW_SPACESHIP = pygame.transform.rotate(pygame.transform.scale(
    YELLOW_SPACESHIP_IMAGE, (SPACESHIP_WIDTH, SPACESHIP_HIEGHT)),90)#改變黃船的尺寸(scale)及面向方向(rotate)
RED_SPACESHIP = pygame.transform.rotate(pygame.transform.scale(
    RED_SPACESHIP_IMAGE, (SPACESHIP_WIDTH, SPACESHIP_HIEGHT)),270)#改變紅船的尺寸(scale)及面向方向(rotate)
SPACE_IMAGE = pygame.image.load(os.path.join('Assets','space.png'))#載入背景
SPACE = pygame.transform.scale(SPACE_IMAGE, (WIDTH, HEIGHT))

def draw_window(red, yellow, red_bullets, yellow_bullets, red_health, yellow_health):
    WINDOW.blit(SPACE, (0, 0))#套入背景
    pygame.draw.rect(WINDOW, BLACK, BORDER)#在視窗的中央處畫上阻隔體
    WINDOW.blit(YELLOW_SPACESHIP, (yellow.x, yellow.y))#把黃色飛船放在(yellow.x,yellow.y)的座標上
    WINDOW.blit(RED_SPACESHIP, (red.x, red.y))#把紅色飛船放在(red.x,red.y)的座標上

    red_health_text = HEALTH_FONT.render("Health: " + str(red_health), 1, WHITE)#Health:+(血量的字串形式),布林函數True或1,顏色
    yellow_health_text = HEALTH_FONT.render("health: " + str(yellow_health), 1, WHITE)
    WINDOW.blit(red_health_text, (WIDTH - red_health_text.get_width() - 10, 10))
    WINDOW.blit(yellow_health_text, (10, 10))

    for bullet in red_bullets :
        pygame.draw.rect(WINDOW, RED, bullet)
    for bullet in yellow_bullets :
        pygame.draw.rect(WINDOW, YELLOW, bullet)
    pygame.display.update()#更新視窗的內容 

def yellow_handle_movement(keys_pressed,yellow):#如果黃船超出邊界範圍(border)外，則按鍵無法起作用
    if keys_pressed[pygame.K_a] and yellow.x - VELOCITY + 5 > 0:
        yellow.x -= VELOCITY
    if keys_pressed[pygame.K_d] and yellow.x + VELOCITY + yellow.width - 15 < BORDER.x:
        yellow.x += VELOCITY
    if keys_pressed[pygame.K_s] and yellow.y + VELOCITY + yellow.height < HEIGHT-10:
        yellow.y += VELOCITY
    if keys_pressed[pygame.K_w] and yellow.y - VELOCITY > 0:
        yellow.y -= VELOCITY

def red_handle_movement(keys_pressed,red):#如果紅船超出邊界範圍(border)外，則按鍵無法起作用
    if keys_pressed[pygame.K_LEFT] and red.x - VELOCITY > BORDER.x + BORDER.width:
        red.x -= VELOCITY
    if keys_pressed[pygame.K_RIGHT] and red.x + VELOCITY + red.width -20 < WIDTH :
        red.x += VELOCITY
    if keys_pressed[pygame.K_DOWN] and red.y + VELOCITY + red.height < HEIGHT-10:
        red.y += VELOCITY
    if keys_pressed[pygame.K_UP] and red.y - VELOCITY > 0:
        red.y -= VELOCITY

def handle_bullets(yellow_bullets, red_bullets, yellow, red):#控制子彈之副函式
        
    for bullet in yellow_bullets :#黃船子彈
        bullet.x += BULLET_VELOCITY #黃船子彈從左邊飛到右邊去
        if red.colliderect(bullet):#如果子彈撞上了紅船
            pygame.event.post(pygame.event.Event(RED_HIT))#event.EVENT建立一新事件->該事件以RED_HIT表示->event.post把該事件放到佇列(queue)末端
            yellow_bullets.remove(bullet)#移除黃船子彈
        elif bullet.x > WIDTH :#如果子彈沒有撞上紅船，然後就這樣撞上邊界牆壁
            yellow_bullets.remove(bullet)#移除黃船子彈

    for bullet in red_bullets :#紅船子彈
        bullet.x -= BULLET_VELOCITY #紅船子彈從左邊飛到右邊去
        if yellow.colliderect(bullet):#如果子彈撞上了黃船
            pygame.event.post(pygame.event.Event(YELLOW_HIT))#event.EVENT建立一新事件->該事件以YELLOW_HIT表示->event.post把該事件放到佇列(queue)末端
            red_bullets.remove(bullet)#移除紅船子彈
        elif bullet.x < 0 :#如果子彈沒有撞上黃船，然後就這樣撞上邊界牆壁
            red_bullets.remove(bullet)#移除紅船子彈

def draw_winner(text):
    draw_text = WINNER_FONT.render(text,1,WHITE)
    WINDOW.blit(draw_text, (WIDTH//2 - draw_text.get_width()//2, HEIGHT//2 - draw_text.get_height()//2))
    pygame.display.update()#更新視窗的內容
    pygame.time.delay(5000)#delay the image for 5000 milliseconds (5 seconds)#畫面停止長達5000毫秒(5秒)

def main():#製造主程式
    red = pygame.Rect(700, 300, SPACESHIP_WIDTH, SPACESHIP_HIEGHT)#Rect代表矩形#red矩形代表紅色飛船：(x座標,y座標,船寬,船高)
    yellow = pygame.Rect(100, 300, SPACESHIP_WIDTH, SPACESHIP_HIEGHT)#yellow矩形代表紅色飛船：(x座標,y座標,船寬,船高)

    yellow_bullets = []#設立一列表(list)，裡面紀錄了黃色飛船射出的子彈
    red_bullets = []#設立一列表(list)，裡面紀錄了紅色飛船射出的子彈

    yellow_health = 10#黃船血量
    red_health = 10#紅船血量

    clock = pygame.time.Clock()#時間常數
    run = True#一開始進入主程式時先設定run是True
    while run :#run如果都是True，那麼迴圈永遠一直進行，如果run變False，那麼就會跳出迴圈遇到pygame.quit()，然後遊戲就會終止
        clock.tick(FPS)#時間控制函式。代表在while這個迴圈是每秒進行60次
        for event in pygame.event.get() :#隨時取得目前遊戲的狀態
            
            if event.type == pygame.QUIT :#如果按下視窗右上角的X鍵時，遊戲就會停止運行，視窗也會關閉，否則永遠不會關
                run = False
                pygame.quit()#遊戲視窗結束
            
            if event.type == pygame.KEYDOWN :#如果按下鍵盤上任何按鍵的瞬間，則要採取行動
                if event.key == pygame.K_LCTRL and len(yellow_bullets) < MAX_BULLET :#如果按下左ctrl且黃色子彈量<最大彈藥量時才會射出
                    bullet = pygame.Rect( yellow.x + yellow.width, yellow.y + yellow.height//2, 10, 5)#子彈從黃船右邊的正中央射出
                    yellow_bullets.append(bullet)#射出的子彈新增在黃色子彈的list裡面
                    BULLET_FIRE_SOUND.play()#放出子彈射出的聲音

                if event.key == pygame.K_RCTRL and len(red_bullets) < MAX_BULLET :#如果按下左ctrl且黃色子彈量<最大彈藥量時才會射出
                    bullet = pygame.Rect( red.x, red.y + red.height//2, 10, 5)#子彈從紅船左邊的正中央射出
                    red_bullets.append(bullet)#射出的子彈新增在紅色子彈的list裡面
                    BULLET_FIRE_SOUND.play()#放出子彈射出的聲音
            
            if event.type == RED_HIT :
                red_health -= 1
                BULLET_HIT_SOUND.play()#放出子彈擊中的聲音

            if event.type == YELLOW_HIT :
                yellow_health -= 1
                BULLET_HIT_SOUND.play()#放出子彈擊中的聲音
        
        winner_text = ""
        if red_health <= 0:
            winner_text = "YELLOW WINS !"
        if yellow_health <= 0:
            winner_text = "RED WINS !"
        if winner_text != "":
            draw_winner(winner_text)
            break

        keys_pressed = pygame.key.get_pressed()#鍵盤讀取函式，類似C語言裡面的mvscrt
        yellow_handle_movement(keys_pressed,yellow)#用鍵盤按鍵WASD控制黃船的移動
        red_handle_movement(keys_pressed,red)#用鍵盤UP,LEFT,DOWN,RIGHT控制紅船的移動
        draw_window( red, yellow, red_bullets, yellow_bullets, red_health, yellow_health)
        handle_bullets(yellow_bullets, red_bullets, yellow, red)      
    main()

if __name__ == "__main__":#確保當程式執行時是優先執行main()，如果有其他的模組帶入，則無法進入這條件式
    main()