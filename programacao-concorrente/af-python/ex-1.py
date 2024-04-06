from time import sleep
from random import randint
from threading import Thread, Lock, Condition

def produtor():
    global buffer
    global item_count
    for i in range(10):
        sleep(randint(0,2))           # fica um tempo produzindo...
        item = 'item ' + str(item_count)
        item_count += 1
        with lock_produtor:
            with lock:
                if len(buffer) == tam_buffer:
                    print('>>> Buffer cheio. Produtor ira aguardar.')
                    lugar_no_buffer.wait()    # aguarda que haja lugar no buffer
                buffer.append(item)
                print('Produzido %s (ha %i itens no buffer)' % (item,len(buffer)))
                item_no_buffer.notify()

def consumidor():
    global buffer
    for i in range(10):
        with lock_consumidor:
            with lock:
                if len(buffer) == 0:
                    print('>>> Buffer vazio. Consumidor ira aguardar.')
                    item_no_buffer.wait()   # aguarda que haja um item para consumir 
                item = buffer.pop(0)
                print('Consumido %s (ha %i itens no buffer)' % (item,len(buffer)))
                lugar_no_buffer.notify()
        sleep(randint(0,2))         # fica um tempo consumindo...

buffer = []
tam_buffer = 5
item_count = 0
lock = Lock()
lock_consumidor = Lock()
lock_produtor = Lock()
lugar_no_buffer = Condition(lock)
item_no_buffer = Condition(lock)
produtor1 = Thread(target=produtor) 
produtor2 = Thread(target=produtor) 
consumidor1 = Thread(target=consumidor) 
consumidor2 = Thread(target=consumidor) 
produtor1.start()
produtor2.start()
consumidor1.start()
consumidor2.start()
produtor1.join()
produtor2.join()
consumidor1.join() 
consumidor2.join() 
