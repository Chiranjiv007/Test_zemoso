# import necessary pieces from Flask
from flask import Flask,render_template,request,jsonify,Response

# Create the app object that will route our calls
app = Flask(__name__)

# Add single endpoint we can use for testing
@app.route('/', methods = ['GET'])
def index():
    return render_template('home.html')

# When run from command line, start the server
if __name__ == '__main__':
    app.run(host = '127.0.0.1', port = 8000, debug = True)
