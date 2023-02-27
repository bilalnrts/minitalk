
# 💬 Minitalk

### 💡 Summery:
The purpose of this project is to code a small data exchange program
using UNIX signals.



## 🛠️ Usage

This project is written in C language and thus you must have gcc compiler and some standart C libraries. If you afford them, you also need "libft". You can find in my repositories. All done.

To compile, go to the project path and run:
```javascript
make all
```
To test the program you have to run the "server" and the "client" in different shell tabs with the following:
```javascript
./server
```
This will show your PID to make the client work and will stay waiting to receive a message from the "client"
  ```javascript
./client "PID" "Your message string"
```
Now you can see "Your message string" on the server window.
## Related

Here are some related projects

[Libft](https://github.com/bilalnrts/libft/tree/main/libft)

  