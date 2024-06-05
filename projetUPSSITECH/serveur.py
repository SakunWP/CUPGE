from flask import Flask, request
app= Flask(__name__)
@app.route("/")
def home():
    return "Hello gauche"
@app.route("/<voit>")
def voitu(voit):
    return f"Hello {voit} "
@app.route('/search',methods=['GET'])
def search():
    args= request.args
    print(args.get("name"), args.get("id"))
    return args
if __name__=="__main__":
    app.run(host='192.168.0.102',port=5000)