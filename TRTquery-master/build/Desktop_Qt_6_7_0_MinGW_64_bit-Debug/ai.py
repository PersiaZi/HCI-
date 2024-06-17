import sys
from zhipuai import ZhipuAI
import io


sys.stdout = io.TextIOWrapper(sys.stdout.buffer, encoding='utf-8')


def get_transfer_route(start, end, api_key):
    client = ZhipuAI(api_key=api_key)
    messages = [
        {"role": "user", "content": f"从 {start} 到 {end} 的地铁换乘路线"}
    ]

    response = client.chat.completions.create(
        model="glm-4",  
        messages=messages
    )


    return print(response.choices[0].message.content)

if __name__ == "__main__":
    if len(sys.argv) < 4:
        print("Usage: python ai.py <start_station> <end_station> <api_key>")
        sys.exit(1)

    start_station = sys.argv[1]
    end_station = sys.argv[2]
    api_key = sys.argv[3]

    route_info = get_transfer_route(start_station, end_station, api_key)
    print(route_info)
