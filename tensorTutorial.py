import tensorflow as tf

node1 = tf.constant(3.0, dtype=tf.float32)
node2 = tf.constant(4.0) #also is tf.float32 but not done implicitly
print(node1,node2)